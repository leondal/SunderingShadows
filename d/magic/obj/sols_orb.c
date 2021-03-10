//sols_orb.c

#include <std.h>
#include <daemons.h>
inherit OBJECT;

object caster;

int level,count;

void miss(object room);



int MR(object ob){
    if (ob->query_property("magic resistance"))
        if ((int)ob->query_property("magic resistance") > random(100))
            return 0;

    return 1;
}

void init(){
    ::init();

    add_action("throw","throw");
}

int throw(string str){
    string target, direction, junk;
    object targ;
    int damage;

    if (!str) return notify_fail("Throw what?\n");

    if (TP->query_paralyzed()) {
        write(TP->query_paralyze_message());
        return 1;
    }
    if (sscanf(str,"%s at %s",junk,target) != 2) {
        if (sscanf(str,"%s %s", junk, direction) != 2) {
            return notify_fail("Usage: throw orb at <person>  or throw orb <direction>\n");
        }
    }
    if (stringp(target)) {
        targ = present(target,ETP);
        if (!targ || !objectp(targ)) return notify_fail("That is not here.\n");
        if (!TP->ok_to_kill(targ)) return notify_fail("Super natural forces prevent you!\n");
        tell_room(ETP,"%^YELLOW%^"+TPQCN+" hurls a glowing orb at "+targ->query_cap_name()+".",({targ,TP}));
        write("%^YELLOW%^You hurl the glowing orb toward "+capitalize(target));
        tell_object(targ,"%^YELLOW%^"+TPQCN+" hurls a glowing orb toward you.");

        if (((int)TP->Thaco(0,targ,0)-3) <= roll_dice(1,20)) {
            tell_room(ETP,"%^YELLOW%^ The orb smashes into "+targ->query_cap_name()+" and explodes in a violent flash.",({TP,targ}));
            write("%^YELLOW%^The orb smashes into "+targ->query_cap_name());
            tell_object(targ,"%^YELLOW%^The orb smashes into you with a violent explosion.");
            damage = roll_dice(level,12);

            if (!MR(targ)) {
                tell_object(targ,"%^YELLOW%^"+
                            caster->query_cap_name()+"'s magic disperses "+
                            "futilely around you.");
                if (present(caster,environment(targ)))
                    tell_object(caster,"%^YELLOW%^Your magic "+
                                "disperses futilely around "+
                                targ->query_cap_name()+".");
                tell_room(environment(targ),"%^YELLOW%^"+
                          caster->query_cap_name()+"'s magic disperses "+
                          "futilely around "+targ->query_cap_name()+".",
                          ({ targ, caster}) );
                TP->set_paralyzed(2,"You are regaining your balance.");
                remove();
                return 1;
            }
            if (!"/daemon/saving_d"->saving_throw(targ, "spell",((int)caster->query_level()/-4))) {
                targ->do_damage("torso",damage);
                targ->set_paralyzed(roll_dice(2,6),"You are stunned by the glowing orb.");
            } else {
                targ->do_damage("torso",damage/2);
            }
            targ->add_attacker(TP);
            if (objectp(targ))
                targ->add_attacker(caster);
            TP->set_paralyzed(2,"You are regaining your balance.");
            remove();
            return 1;
        } else {
            tell_room(ETP,"%^YELLOW%^The glowing orb misses its target and falls to the ground.");
            miss(ETP);

        }

        TP->set_paralyzed(2,"You are regaining your balance.");
        return 1;
    } else {
        if (!pointerp(ETP->query_exits())) return notify_fail("No exits here.\n");
        if (member_array(direction,ETP->query_exits()) == -1) return notify_fail("That direction is not an option.\n");

        tell_room(ETP,"%^BLUE%^"+TPQCN+" throws a glowing orb toward the "+direction+".",TP);
        write("%^BLUE%^You hurl the orb toward the "+direction+".");
        miss(find_object_or_load(ETP->query_exit(direction)));

    }

    TP->set_paralyzed(2,"You are regaining your balance.");
    return 1;
}

miss(object room){
    if (!objectp(room)) remove();
    TO->move(room);
    tell_room(room,"%^BOLD%^%^YELLOW%^A glowing orb hits the ground in front of you.");
    call_out("boom",4,room);


}

void boom(object room){
    object *inven;
    object targ;
    int damage, i,j;

    if (!objectp(room)) return;
    inven = all_living(room);
//    inven = filter_array(inven, "is_non_immortal_player",FILTERS_D);
//This filter only finds players.  Changing it.  Circe 11/22/04
    inven = filter_array(inven, "is_non_immortal",FILTERS_D);
    tell_room(room,"%^BOLD%^%^YELLOW%^In a blinding flash the orb explodes.");
    j = sizeof(inven);
    for (i = 0;i<j;i++) {
        targ = inven[i];
        if (!objectp(targ)) continue;
        damage = roll_dice(level/2,10);
        tell_object(caster,"boom damage = "+damage);
        if (!MR(targ)) {
            tell_object(targ,"%^YELLOW%^"+
                        caster->query_cap_name()+"'s magic disperses "+
                        "futilely around you.");
            if (present(caster,environment(targ)))
                tell_object(caster,"%^YELLOW%^Your magic "+
                            "disperses futilely around "+
                            targ->query_cap_name()+".");
            tell_room(environment(targ),"%^YELLOW%^"+
                      caster->query_cap_name()+"'s magic disperses "+
                      "futilely around "+targ->query_cap_name()+".",
                      ({ targ, caster}) );

            continue;
        }

        if (!"/daemon/saving_d"->saving_throw(targ, "spell",((int)caster->query_level()/-4))) {
            targ->do_damage("torso",damage);
            targ->set_paralyzed(roll_dice(2,3),"You're stunned by the glowing orb.");
        } else {
            targ->do_damage("torso",damage/2);

        }
        targ->add_attacker(TP);
        if (!objectp(targ)) continue;
        targ->continue_attack();
    }
    remove();


}
void set_caster(object caster1){
    caster = caster1;
}

void set_level(int level1){
    level = level1;
}

void create(){

    ::create();
    set_name("orb");
    set_short("%^YELLOW%^Searing orb");
    set_long("This hot glowing orb pulsates with power, ready to explode at any time.");
    set_property("magic",1);
    set_weight(10);
    set_id(({"orb","sols orb","sol's orb","sol's searing orb","searing orb"}));
    set_heart_beat(3);
    set_property("no animate",1);
}

void heart_beat(){
    int damage;
    if (!objectp(ETO)) return;
    if (ETO->query_ghost()) {
        remove();
        return;
    }
    if (count >= level || ETO != caster) {

        if (!ETO->is_living()) {
            boom(ETO);
            return;

        }
        tell_object(ETO, "%^YELLOW%^The orb has reached its threshhold and explodes violently.");
        damage = roll_dice(level,10);
        if (!"/daemon/saving_d"->saving_throw(ETO, "spell",((int)caster->query_level()/-4))) {
            ETO->do_damage("torso",damage);
            ETO->set_paralyzed(roll_dice(2,6),"You're stunned by the glowing orb.");
        } else {
            ETO->do_damage("torso",damage/2);
        }
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        remove();
        return;

    }

    count++;
    tell_object(ETO,"%^YELLOW%^That orb is getting hot.");
    ETO->do_damage("torso",count);
    ETO->add_attacker(TO);
    ETO->continue_attack();
    ETO->remove_attacker(TO);
}
