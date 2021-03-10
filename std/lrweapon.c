#include <config.h>
#include <std.h>
#include <daemons.h>
#define VOID "/d/shadowgate/void"
inherit WEAPON;

object ammunition;
nosave int reload, reloadCount;
string prof_type, lr_type = "piercing";
int twoHanded;
int s_range, m_range, l_range;
int rate_of_fire, current_range;
string ammo;
object current_ammo;
nosave mapping targets = ([]);
nosave int mPerfect;

void create() {
    ::create();
    set_rate_of_fire(2);
}

void heart_beat() {
    reload = 0;
    reloadCount = 0;
}

void set_two_handed() {
    twoHanded = 1;
}

int query_two_handed() {
    return twoHanded;
}

int query_size() {

    int o;
    int s = ::query_size();

    if(!twoHanded) {
        return s;
    } else {
        if (objectp(ETO)) {
            o = ETO->query_size();
        } else {
            o = 2;
        }
        if(s > o) {
            return s;
        } else {
            return o+1;
        }
    }

}


void set_wielded(object ob) {
    ::set_wielded(ob);
    add_action("__Shoot","shoot");

    if(!TP->query_skill(query_lr_prof_type())) {
        TP->add_skill(query_lr_prof_type(),1);
    }

}

int unequip() {

    if(!::unequip()) {
        return 0;
    }
    remove_action("__Shoot","shoot");
    return 1;
}

object errant_hit(object foe) {
    int i;

    object *inven = all_inventory(environment(foe));
    if(random(30)< sizeof(inven)) {
        return inven[random(sizeof(inven))];
    }
    return 0;

}

int __Shoot(string str) {
    string target,dir,mdir,file,msg, whom,fdir;
    int distance,inc,to_hit,tohitroll,damage, hit,perfect, x;
    int thaco, flag, autoAim;
    object current,alt_foe,foe,ammo,env, *roomList;

    if(this_player()->query_property("minion"))
        return 1;

    if(!str)
        return notify_fail("Syntax: shoot [target] [dir] [distance] || shoot [target] [dir]\n");
    if(sscanf(str,"%s %s %d",target,dir,distance) != 3){
        if(sscanf(str, "%s %s", target, dir) != 2){
            return notify_fail("Syntax: shoot [target] [dir] [distance] || shoot [target] [dir]\n");
        }
        autoAim = 1;
        distance = query_range(2);
    }
    if(!TO->query_wielded()) return 0;
    if(ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info", ETO);
        return 1;
    }
// adding check for paralyzed & blind *Styx* 12/24/03, last change 10/09/03
    if(ETO->query_blind())
        return notify_fail("You can't see so you can't really aim long range.\n");
    mdir = query_type();
    set_type(lr_type);
    if (!wieldable()) {
        write("You can't use this as a missile weapon.");
        set_type(mdir);
        mdir = "";
        return 1;
    }
    set_type(mdir);

    if(!ammo = present(TO->query_ammo(),ETO))
        return notify_fail("You don't have any "+query_ammo()+" for this "+query_name()+"!\n");
    if(reload && userp(ETO)) {
        write("You are reloading");
        return 1;
    }
    if(distance < 1)
        return notify_fail("You don't need much aim to kill that.\n");

    x = TP->light_blind(0);
    if(x)
    {
        tell_object(TP, TP->light_blind_fail_message(x));
        return 1;
    }

    if(dir == "rift")
        return notify_fail("You can't get a clear shot through the magical passage.\n");
    switch(dir){
    case "n": dir = "north";
        break;
    case "ne": dir = "northeast";
        break;
    case "e": dir = "east";
        break;
    case "se": dir = "southeast";
        break;
    case "s": dir = "south";
        break;
    case "sw": dir = "southwest";
        break;
    case "w": dir = "west";
        break;
    case "nw": dir = "northwest";
        break;
    default: dir = dir;
        break;
    }
    if((string)environment(ETO)->query_exit(dir) == VOID)
        return notify_fail("You want to shoot the walls?\n");

    if(is_broken()) {
        return notify_fail("The bow is broken.");
    }

    current = EETO;
    roomList = allocate(distance);
    roomList[0] = current;

    if(distance > query_range(2))
        return notify_fail("This weapon will not shoot that far!\n");
    if (current->query_door(dir)
        && !current->query_open(current->query_door(dir))) {
        write("There seems to be a closed door between you and your target.");
        return 1;
    }
    for(inc = 0;inc < distance;inc ++) {
        current = find_object_or_load((string)current->query_exit(dir));
        if (autoAim && present(target,current)) {
            break;
        }

        if(inc < distance-1) {

            roomList[inc+1] = current;
            //tell_room(current,"Something whizzes by your head!");
            if((string)current->query_exit(dir) == VOID)
                return notify_fail("Your shot flies off and hits nothing!\n");
        }
        if(current->query_property("indoors")) {

            if((environment(TO)->query_property("indoors")) &&
               (distance > 1)) {
                return notify_fail("You can only shoot one room away when shooting from indoors to indoors!\n");
            } else if(environment(TO)->query_property("indoors")) {
                if(inc < distance-1) {
                    return notify_fail("You can not shoot through the indoors!\n");
                } else
                    return notify_fail("You can not shoot from the outdoors to the indoors!\n");
            }
        }
        if (current->query_door(dir)
            && !current->query_open(current->query_door(dir))) {
            write("There seems to be a closed door between you and your target.");
            return 1;
        }
    }


    x = TP->light_blind_remote(0, current, distance);

    if (x !=0)
    {
        tell_object(TP, "You can't see well enough to shoot into that room");
        tell_object(TP, TP->light_blind_fail_message(x));
        return 1;
    }
    foe = present(target,current);

    if(!objectp(foe) || foe->query_unconscious())
        foe = present(target + " 2", current);

    if(!objectp(foe))
        return notify_fail("There is no "+target+" there!\n");
    if(!TP->ok_to_kill(foe))
        return notify_fail("Greater forces prevent your malice.\n");

    if(foe->query_property("no bows"))
        return notify_fail("You can't seem to get a clean shot at them from here!!\n");

    tell_room(ETP,TPQCN+" loads "+TPQP+" "+query_name()+" with "+query_ammo()+" and shoots "+dir+"!",TP);

    tell_object(ETO,"You load your "+query_name()+" with "+query_ammo()+" and shoot "+dir+"!");
    message("combat", capitalize(query_ammo())+" flies "+dir+".\n", roomList, ETP);

    reloadCount++;
    if(reloadCount == calc_speed()) {
        reload=1;
    }

    tohitroll = random(20)+1;
    if(living(foe))
        TP->kill_ob(foe,1);
    if(tohitroll == 20) perfect = 1;
    //else if(tohitroll == 1) perfect = -1;

    else perfect = 0;

    tohitroll -= inc-1;

    if((distance > query_range(0)) && (distance <= query_range(1)))
        tohitroll -= 2;
    if(distance >= query_range(1))
        tohitroll -= 5;

    if(TP->query_class() == "ranger")
    {
        if(TP->is_favored_enemy(foe))
        {
            tohitroll += 2;
            tohitroll += (FEATS_D->usable_feat(TP, "second favored enemy") * 2);
            tohitroll += (FEATS_D->usable_feat(TP, "third favored enemy") * 2);

            if(foe->is_undead() && FEATS_D->usable_feat(TP, "slay the undead"))
                tohitroll += 2;
        }
    }

    tohitroll = adjust_to_hit(tohitroll);
    thaco = ETO->Thaco(1,foe,TO);
    flag = 1;
    whom = foe->query_cap_name();

    if(autoAim) {
        for(inc = 0;inc < sizeof(roomList);inc++) {
            if(!objectp(roomList[inc])) {
                roomList -= ({roomList[inc]});
                continue;
            }
        }
    }
    fdir = current->query_direction(base_name(roomList[sizeof(roomList) - 1]));

    if(!fdir || fdir == "/d/shadowgate/void") {
        fdir = "out of nowhere";
    }

    if(((tohitroll < thaco ) && (perfect != 1)) || perfect == -1) {
        if(objectp(alt_foe = errant_hit(foe)) && (random(20) > ETO->Thaco(1,alt_foe,TO))) {
            tell_room(current,"A " + capitalize(query_ammo())+" from "+fdir+" flies by "+whom+".",foe);
            tell_object(foe,"A "+ capitalize(query_ammo())+" from "+fdir+" barely misses you!");
            foe = alt_foe;
        } else {
            flag = 0;
            tell_room(current,"A " + capitalize(query_ammo())+" from "+fdir+" flies by "+whom+".",foe);
            tell_object(foe,"A "+ capitalize(query_ammo())+" from "+fdir+" barely misses you!");
            write("You missed...");
        }
    }
    if(flag) {
        if(perfect || mPerfect) write("Perfect shot!");
        if(foe->query_size() > 2)
            damage = query_large_damage();
        else
            damage = query_damage();

        damage = damage_done(foe, damage);

        damage += TP->query_property("damage bonus");

        if(TP->query_class() == "ranger")
        {
            if(TP->is_favored_enemy(foe))
            {
                damage += 2;
                damage += (FEATS_D->usable_feat(TP, "second favored enemy") * 2);
                damage += (FEATS_D->usable_feat(TP, "third favored enemy") * 2);

                if(foe->is_undead() && FEATS_D->usable_feat(TP, "slay the undead"))
                    damage += 2;
            }
        }

        if (perfect || mPerfect) {
            damage=damage*4;
            if(FEATS_D->usable_feat(TP, "smite the lifeless") && foe->is_undead() && (foe->query_level() < TP->query_level() + 7 ))
            {
                if(!foe->fort_save(TP->query_level()))
                {
                    write("Your shot smites your undead foe into dust!");
                    foe->cause_typed_damage(foe, "body", foe->query_max_hp() + 500, "divine");
                }
            }
        }
        tell_room(current,"A "+ capitalize(query_ammo())+" from "+fdir+" hits "+whom+"!",foe);

        write("You hit "+whom+"!");
        tell_object(foe,"A "+ capitalize(query_ammo())+" from "+fdir+" hits you!");

        foe->add_attacker(ETO);
        //hit = (int)foe->do_damage(foe->return_target_limb(),damage);
        foe->cause_typed_damage(foe, "body", damage, "piercing");
        if(objectp(current_ammo)) {
            foe->add_poisoning(current_ammo->query_poisoning());
        }
        if( !objectp(foe)){
            write("You have killed "+whom+"!!!");
            return 1;
        }
        foe->bow_hit(TO, damage);

        foe->add_attacker(TP);

        if(foe->check_death()) {
            write("You have killed "+whom+"!!!");
            return 1;
        }
    }

    if(!userp(foe) && living(foe)){
        env = environment(foe);
        file = base_name(EETO);
        if(foe->query_paralyzed() || ((object *)foe->query_attackers()!= ({})
                                      && (member_array(ETO,foe->query_attackers()) == -1 && !present(ETO,EETO)))) {
            return 1;
        } else {
            if(!living(foe)) {
                return 1;
            }
            if(!targets[foe] || targets[foe] == ({})) {

                call_out("move_monster",2,foe, ETO);
            }
            targets[foe] = roomList;
        }
    }
    return 1;
}


void move_monster(object foe, object player) {
    object * roomList;
    object current;
    int grx,grnum_p;
    object *grplayers,grhere,grvictim;

    if(!objectp(foe)) {
        return;
    }
    if(!targets[foe]) {
        return;
    }

    if(foe->query_paralyzed() || ((object *)foe->query_attackers()!= ({})
                                  && (member_array(TP,foe->query_attackers()) == -1 && !present(TP,ETO)))) {

        return 1;
    }

    roomList = targets[foe];
    if(!pointerp(roomList) || !sizeof(roomList)) {
        return;
    }

    current = roomList[sizeof(roomList)-1];


    grhere = environment(foe);
    foe->move_player(current, "in a rage");
    foe->kill_ob(player,1);

    if(foe->query_property("swarm")) {
        grplayers = all_inventory(grhere);
        grplayers -= ({foe});
        grnum_p = sizeof(grplayers);
        for(grx = 0;grx < grnum_p;grx++) {
            grvictim = grplayers[grx];
            if(living(grvictim) && !userp(grvictim) && grvictim->query_property("swarm") && grvictim != foe && !grvictim->query_paralyzed()) {

                grvictim->move_player(current, "in a rage");
                TP->kill_ob(grvictim,1);
                //grvictim->force_me("kill "+TPQN);
            }
        }
    }
    roomList -= ({current});
    targets[foe] = roomList;
    if(sizeof(roomList)) {

        call_out("move_monster",2,foe,player);
    }

}

void set_rate_of_fire(int rate) {
    rate_of_fire = rate;
    set_heart_beat(rate_of_fire);
}
void query_rate_of_fire() {
    return rate_of_fire;
}
void set_current_range(int range) {
    current_range = range;
}

int query_current_range() {
    return current_range;
}

int query_ammo_damage() {
    object ammo1 = present(TO->query_ammo(),TP);
    if(!objectp(ammo1)) {
        return 0;
    }
    current_ammo = ammo1;
    return ammo1->query_ammo_damage();
}

int query_large_ammo_damage() {
    object ammo1 = present(TO->query_ammo(),TP);
    if(!objectp(ammo1)) {
        return 0;
    }
    current_ammo = ammo1;
    return ammo1->query_large_ammo_damage();

}

int is_lrweapon() {return 1;}


void set_range(int s, int m, int l) {
    s_range = (s > 0) ? s : 1;
    m_range = (m > 0) ? m : 2;
    l_range = (l > 0) ? l : 3;
}

int query_range(int range) {
    if(range == 0) return s_range;
    if(range == 1) return m_range;
    if(range == 2) return l_range;

}

int set_ammo(string str) {
    ammo = str;
}

string query_ammo() {
    if(!ammo) return 0;
    else return ammo;
}
void set_lr_prof_type(string type) {
    prof_type = type;
}
string query_lr_prof_type() {
    if(!prof_type) return "unknown";
    return prof_type;
}

int damage_done(object foe,int damage) {

    damage += COMBAT_D->get_lrdamage(TP, TO, foe);

    return damage;
}

int adjust_to_hit(int tohit) {
    int prof;
    prof = TP->query_skill(query_lr_prof_type());
    prof += (random(60) - 30);

    if(prof == 0) {
        return 0;
    }
    tohit =  (tohit*prof)/100;
    return tohit;

}
object get_current_ammo() {
    return current_ammo;
}

/*
int calc_speed() {
    int prof;
    int speed = 1;

    prof = ETO->query_skill(query_lr_prof_type());
    if(prof > 99) {
        speed++;
    }
    prof -= 15;
    while(prof > 99) {
        speed++;
        prof -= 15;
    }
    return speed;
}
*/

int calc_speed()
{
    int speed,
        ranger,
        fighter,
        arcane;

    ranger  = ETO->query_class_level("ranger");
    arcane  = ETO->query_class_level("arcane_archer");
    fighter = ETO->query_class_level("fighter");

    speed = 1 + max( ({ ranger / 20, arcane / 10, fighter / 40 }) );

    return speed;
}

void set_lr_type(string type){
    lr_type = type;
}

string get_lr_type(){
    return lr_type;
}

void set_perfect(){
    mPerfect = !mPerfect;
}
