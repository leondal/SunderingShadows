// Changed charge damage and added a trample effect.  I had to chop thecode up
// and move things around a bit so it all worked. -Ares
#include <std.h>
#include <daemons.h>

inherit OBJECT;

#define tpqcn tp->query_cap_name()
#define FEATTIMER 35; // circa six rounds wait equivalent per target at current speed. -N, 9/10.

object tp, env;
int time, flag, rooms, level, counter;
string target;

int DEBUG;

int can_charge(object who);
int weapon_check(object *weapon);
void debug_message(string str);

void create()
{
    ::create();
    set_heart_beat(1);
    set_no_clean(1);
    DEBUG = 1;
}

void set_target(string x) { target=x; }

void set_tp(object x)
{
    tp    = x;
    level = tp->query_base_character_level();
    env   = environment(tp);
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(tp))
    {
        remove();
        return;
    }

    if (counter > 3)
    {
        if(env == environment(tp))
        {
            tell_object(tp,"%^BOLD%^%^BLUE%^You have not continued the charge, you pull your horse up.");
            tell_room(environment(tp),"%^BOLD%^%^BLUE%^"+tp->QCN+" pulls "+tp->QP+" horse up.",tp);
            tp->remove_property("charging");
            tp->remove_property("charging object");
            tp->remove_property("using instant feat");
            tp->remove_property("charge_target_found");
            remove();
            return;
        }
        else { counter = 0; }
    }

    counter++;

    if(time >= level && level > 0)
    {
        if (objectp(tp))
        {
            tell_object(tp,"%^BOLD%^%^BLUE%^You have expended too much energy on charging, you pull your horse up.");
            tell_room(environment(tp),"%^BOLD%^%^BLUE%^"+tp->QCN+" pulls "+tp->QP+" horse up.",tp);
            tp->remove_property("charging");
            tp->remove_property("charging object");
            tp->remove_property("using instant feat");
            tp->remove_property("charge_target_found");
        }
        remove();
        return;
    }

    time++;

    //if(objectp(tp)) tell_object(tp,"timer = "+time+" counter = "+counter);

    if(objectp(tp))
    {
        if(!tp->query_property("charge_target_found")) TO->do_work();
    }
}


void do_harm(int damage, object ob, object play)
{
    int thaco,roll;
    object *weapon;

    if(!objectp(TO)) { return; }
    // added weapon & in_vehicle checks *Styx* 12/24/03, last change 10/17/03


    if (!objectp(play)) {
        remove();
        return;
    }

    weapon = play->query_wielded();

    play->remove_property("using instant feat");
    play->remove_property("charging object");
    play->remove_property("charging");
    play->remove_property("charge_target_found");
    if(!objectp(ob)) {
        remove();
        return;
    }
    if (play->query_bound() || play->query_tripped()) {
        play->send_paralyzed_message("info",play);
        remove();
        return;
    }
    if(ob->query_deaths_door()) {
        remove();
        return;
    }
    if(!present(ob, environment(play))) {
        tell_object(play,"%^BOLD%^You realize that your opponent has escaped your charge.");
        tell_object(ob,"%^BOLD%^You have safely elluded "+play->QCN+"\'s charge!");
        remove();
        return;
    }
    if((weapon == ({}))) {
        notify_fail("You fail to do any damage weaponless!\n");
        remove();
        return 0;
    }
    if(weapon[0]->is_lrweapon()) {
        notify_fail("That weapon is not designed for such an attack!\n");
        remove();
        return 0;
    }

    /*
    if(!weapon[0]->query_property("lance")) {
        notify_fail("Without a lance, your charge fails.\n");
        remove();
        return;
    }*/

    if(!weapon_check(weapon))
    {
        remove();
        return 0;
    }

	if((play->query_race() != "centaur") && (play->query_race() != "wemic")) {
    if(!play->query_in_vehicle() || !objectp((object)play->query_in_vehicle())) {
        notify_fail("Your charge fails since you are no longer mounted.\n");
        remove();
        return;
    }
	}

    thaco  = tp->Thaco(1,ob,weapon[0],"cavalier");
    roll   = (roll_dice(1,20)-rooms);

    TO->set_property("ended_charge",1);

    if( thaco <= roll) {
        tell_object(play,"%^BOLD%^You successfully ride with the power of your steed behind you into "+ob->QCN+"!");
        tell_room(environment(play),"%^BOLD%^"+play->QCN+" rides with tremendous force into "+ob->QCN+"!",({ob,play}));
        tell_object(ob,"%^BOLD%^"+play->QCN+" rides with tremendous force into you, "+play->QP+" weapon doing great damage!\n");
        //play->set_disable(1,ob);
        ob->kill_ob(tp,1);
        play->cause_typed_damage(ob,ob->return_target_limb(),damage,weapon[0]->query_damage_type());
        play->cause_typed_damage(ob,ob->return_target_limb(),(int)play->get_damage(weapon[0]),weapon[0]->query_damage_type());
        ob->set_paralyzed(8,"You are recovering from that last hit.");
    }
    else {
        tell_room(environment(tp),"%^BOLD%^%^BLUE%^As "+tpqcn+" charges, "+ob->QCN+" manages to dodge the attack.",({tp,ob}));
        tell_object(tp,"%^BOLD%^%^BLUE%^"+ob->QCN+" dodges your charge.");
        tell_object(ob,"%^BOLD%^%^BLUE%^You successfully dodge the charge.");
    }

    flag = 1;
    tp->remove_property("charging");
    tp->remove_property("charging object");
    tp->remove_property("using instant feat");
    tp->remove_property("charge_target_found");

    //call_out("remove",1);

    remove();

    return;
}

// Could possibly consider making trample into it's own object to randomly trample stuff on heartbeat
// instead of firing right before charge lands.  Would risk trampling and charging the same target tho
void do_trample(int damage,object targ,object play) {
    int i,dam,mod,bonus,roll,thaco,cbonus;
    object *attackers,room,*weapon;

    if(!objectp(TO)) { return; }
    if(!objectp(play)) return;
    play->remove_property("using instant feat");
    if(!objectp(targ)) { return; }
    if(!objectp(room=environment(play))) { return; }
    if (play->query_bound() || play->query_tripped() || play->query_paralyzed()) {
        play->send_paralyzed_message("info",play);
        remove();
        return;
    }
    
	if((play->query_race() != "centaur") && (play->query_race() != "wemic")) {
	if (!play->query_in_vehicle() || !objectp((object)play->query_in_vehicle())) {
        notify_fail("Your charge fails since you are no longer mounted.\n");
        remove();
        return;
    }
	}

    if(!FEATS_D->usable_feat(play,"trample")) return;

    attackers = play->query_attackers();
    if(member_array(targ,attackers) != -1 ) { attackers -= ({ targ }); }
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    roll   = (roll_dice(1,20)-rooms);
    weapon = tp->query_wielded();
    if(weapon == ({})) {
        remove();
        return;
    }

    // There's a thaco check to see if the trample lands, and a random roll modified by the
    // dex bonus.  I don't think it should hit everything, and hopefully with two layers here
    // it should seem pretty random. -Ares
    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            if((int)attackers[i]->query_property("trampled") > time()) { continue; } // So they can't get trampled more than once
            attackers[i]->set_property("trampled",time() + 10);
            thaco  = tp->Thaco(1,attackers[i],weapon[0],"cavalier");
            if( thaco >= roll)
            {
                tell_object(tp,"%^BOLD%^"+attackers[i]->QCN+" easily avoids being trampled by your mount!%^RESET%^");
                tell_object(attackers[i],"%^BOLD%^You easily avoid "+tp->QCN+"'s trampling mount!%^RESET%^");
                tell_room(environment(tp),"%^BOLD%^"+attackers[i]->QCN+" easily avoids "+tp->QCN+"'s trampling "
                    "mount!%^RESET%^",({tp,attackers[i]}));
                continue;
            }
            bonus  = "/daemon/bonus_d.c"->query_dex_bonus(attackers[i]);
            cbonus = level/5;
            if((roll_dice(1,20) + bonus) < (roll_dice(1,20) - cbonus) ) // Might need to tweak this until we find a good balance
            {
                tell_object(tp,"%^MAGENTA%^"+attackers[i]->QCN+" dodges out of the way as you "
                    "charge towards "+targ->QCN+"!");
                tell_object(attackers[i],"%^MAGENTA%^You dodge out of the way as "+tp->QCN+" charges "
                    "towards "+targ->QCN+"!%^RESET%^");
                tell_object(targ,"%^MAGENTA%^"+attackers[i]->QCN+" dodges out of the way as "+tp->QCN+" charges "
                    "towards you!%^RESET%^");
                tell_room(environment(tp),"%^MAGENTA%^"+attackers[i]->QCN+" dodges out of the way "
                    "as "+tp->QCN+" charges towards "+targ->QCN+"!%^RESET%^",({ targ,tp,attackers[i]}) );
                continue;
            }
            dam = damage;
            mod = roll_dice(1,20);
            dam = (dam * (50 + mod))/100; // 50-70 percent of charge damage done in trample

            tell_object(attackers[i],"%^BOLD%^%^BLUE%^"+play->QCN+" tramples over you as they charge headlong "
                "towards "+targ->QCN+"!%^RESET%^");
            tell_object(tp,"%^BOLD%^%^BLUE%^You trample over "+attackers[i]->QCN+" as you charge "
                "towards "+targ->QCN+"!%^RESET%^");
            tell_room(environment(tp),"%^BOLD%^%^BLUE%^"+tp->QCN+" tramples over "+attackers[i]->QCN+" "
                "as "+tp->QS+" charges towards "+targ->QCN+"!%^RESET%^",({targ,tp}));
            attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), dam, weapon[0]->query_damage_type());
        }
    }

    return;
}


int do_room(string str) {
    object ob, *weapon, *keyz;
    int damage, duration, added, tramp_time, level, timerz, i;
    mapping tempmap, newmap;

    if(!objectp(TO)) { return 0; }

    if (!can_charge(tp)) {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        remove();
        return 0;
    }
    if (!(ob = present(str,environment(tp)))) {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        tell_object(tp,"Your target is not in range!\n");
        remove();
        return 0;
    }
    tempmap = tp->query_property("using charge");
    if(mapp(tempmap)) {
        if(tempmap[ob] > time()) {
          tp->remove_property("charging");
          tp->remove_property("charging object");
          tp->remove_property("using instant feat");
          tp->remove_property("charge_target_found");
          tell_object(tp,"That target is still wary of such an attack!");
          remove();
          return 0;
        }
    }
    if (ob==tp) {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        tell_object(tp,"You want to charge yourself, you fool?");
        remove();
        return 0;
    }
    if (!tp->ok_to_kill(ob)) {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        tell_object(tp,"Supernatural forces prevent your attack.\n");
        remove();
        return 0;
    }
    if (ob->query_property("no rush")) {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        tell_object(tp,"You can't really charge that.");
        remove();
        return 0;
    }

	if((tp->query_race() != "centaur") && (tp->query_race() != "wemic")) {
	if (!tp->query_in_vehicle() || !objectp((object)tp->query_in_vehicle())) {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        tell_object(tp,"You need to be mounted to do that.\n");
        remove();
        return 0;
    }}


    tp->clean_up_attackers();
    ob->clean_up_attackers();
    ob->kill_ob(tp,1);
    tp->kill_ob(ob,1);
    level = tp->query_base_character_level();
    tp->set_property("charging",1);
	if((tp->query_race() == "centaur") || (tp->query_race() == "wemic")){
        tell_room(environment(tp),"%^BOLD%^%^BLUE%^"+tpqcn+" charges at full speed",tp);
        tell_object(tp,"%^BOLD%^%^BLUE%^You charge at full speed!");
    }
	 else{
    tell_room(environment(tp), "%^BOLD%^%^BLUE%^"+tpqcn+" digs "+tp->QP+" heels into "+tp->QP+" "+tp->query_in_vehicle()->QCN+".",tp);
    tell_object(tp,"%^BOLD%^%^BLUE%^You dig your heels into your "+tp->query_in_vehicle()->QCN+".");
	 }
    tell_object(ob,"%^BOLD%^%^BLUE%^"+tpqcn+" is charging toward you!!!");

    weapon = tp->query_wielded();
    if((int)ob->query_size() < 3)   { damage = weapon[0]->query_damage(); }
    else                            { damage = weapon[0]->query_large_damage(); }

    damage += "/daemon/bonus_d"->damage_bonus(tp->query_stats("strength"));

    added = rooms;
    if(added > 5 && ob->is_player()) { added = 5; }
    damage += added * (random(level)+10); // Adds random(level) + 10 damage per room up to a max of 5 in pkill

    damage += roll_dice(level,6); //tuned to d6 like most skills these days!

    if (ob->query_property("weapon resistance"))
    {
        if((weapon[0]->query_property("enchantment")) < (ob->query_property("weapon resistance")) )
        {
            damage = 0;
        }
    }
    duration = 5;
    duration = duration - rooms;
    if(duration < 1) { duration = 1; }
    tramp_time = duration - 1;
    flag = 1;

    tempmap = ([]);
    tempmap = tp->query_property("using charge"); // adding per-target tracking. -N, 9/10.
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,ob);
    newmap = ([]);
    keyz = keys(tempmap);
    if(sizeof(keyz)) {
      for(i=0;i<sizeof(keyz);i++) { if(objectp(keyz[i])) newmap += ([ keyz[i] : tempmap[keyz[i]] ]); }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ ob : timerz ]);
    tp->remove_property("using charge");
    tp->set_property("using charge",newmap);

    call_out("do_harm",duration,damage,ob,tp);
    call_out("do_trample",tramp_time,damage,ob,tp);
    return 1;
}


int can_charge(object who)
{
    object *weapon;

    if(!objectp(who)) return 0;
    weapon = who->query_wielded();

    if (who->query_bound() || who->query_tripped() || who->query_paralyzed())
    {
        who->send_paralyzed_message("info",TP);
        return 0;
    }
    if ((weapon == ({})))
    {
        write("This attack is useless without weapons!\n");
        return 0;
    }
    if(weapon[0]->is_lrweapon()) {
        notify_fail("That weapon is not designed for such an attack!\n");
        remove();
        return 0;
    }
    /*
    if (!weapon[0]->query_property("lance"))
    {
        write("You can charge with only one kind of weapon, a lance.\n");
        return 0;
    }*/

    if((who->query_race() != "centaur") && (who->query_race() != "wemic")) {
	if (!who->query_in_vehicle() || !objectp((object)who->query_in_vehicle()))
    {
        write("You need to be mounted to do that.\n");
        return 0;
    }
	}
    if (environment(who)->query_property("no charge"))
    {
        if (environment(who)->query_charge_message() == 0) tell_object(who,"You are unable to charge in this room.");
        else tell_object(who,environment(who)->query_charge_message());
        return 0;
    }
    if (who->query_disable())
    {
        // added to explain why charge might not work.
        tell_object(who,"You are unable to disengage from combat just yet.");
        return 0;
    }
    return 1;
}


void do_work()
{
    if(!objectp(TO)) { return; }
    if(!objectp(tp)) { return; }
    if(!objectp(environment(tp))) { return; }
    if(!can_charge(tp))
    {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        remove();
        return;
    }

    message("info", "%^BOLD%^%^BLUE%^You hear the thunder of charging hooves in the distance.", nearbyRoom(environment(tp),3),tp);
    message("info","%^BOLD%^%^BLUE%^You charge forward", tp);

    if(present(target, environment(tp)))
    {
        tp->set_property("charge_target_found",1);
        do_room(target);
        return;
    }

    rooms++;

    if (rooms >= level)
    {
        tell_object(tp,"%^BOLD%^%^BLUE%^You've charged as far as you can.");
        tell_room(environment(tp),"%^BOLD%^%^BLUE%^"+
        tp->QCN+" pulls "+tp->QP+" horse up.",tp);
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        remove();
        return;
    }
}

void do_exit()
{
    if(!objectp(TO)) { return; }
    if (flag) return;
    if (query_verb() == "up" || query_verb() == "down"|| query_verb() == "climb"|| query_verb() == "descend") {
        tell_object(tp,"%^BOLD%^%^BLUE%^You cannot charge "+query_verb()+".");
        tell_room(environment(tp),"%^BOLD%^%^BLUE%^"+tp->QCN+" pulls "+tp->QP+" horse up.",tp);
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
        remove();
        return;
    }
    do_work();
    counter = 0;
}

void remove()
{
    if(!objectp(TO)) { return; }
    if (objectp(tp))
    {
        tp->remove_property("charging");
        tp->remove_property("charging object");
        tp->remove_property("using instant feat");
        tp->remove_property("charge_target_found");
    }
    set_no_clean(0);
    ::remove();
}


int weapon_check(object *weapon)
{
    int skill,effective_size,DC,result;
    string prof,message,*ids;

    if(!objectp(tp)) { return 0; }

    if(!pointerp(weapon) || !sizeof(weapon) || !objectp(weapon[0]) || !weapon[0]->is_weapon())
    {
        notify_fail("You need to be wielding a weapon in order to charge!\n");
        return 0;
    }

    prof = (string)weapon[0]->query_weapon_prof();

    ids = weapon[0]->query_id();

    if(member_array(prof,({"simple","martial","exotic"})) == -1)
    {
        notify_fail("Error, your "+weapon[0]->query_short()+" does not have a valid weapon type, please contact a wiz.\n");
        return 0;
    }

    message =  ""+ctime(time())+"\n";
    message += "\t"+tp->QCN+" charged\n";

    effective_size = (int)weapon[0]->query_size() - (int)tp->query_size();

    message += "\t"+tp->QCN+" used "+identify(weapon[0])+", effective size in relation to wielder: "+effective_size+"\n";

    message += "\t Prof type: "+prof+"\n";

    skill = (int)tp->query_skill("athletics");

    message += "\t"+tp->QCN+" has an athletics skill of: "+skill+"\n";

    DC = 10;

    message += "\t Beginning DC of 10\n";

    if(tp->is_class("paladin") || tp->is_class("cavalier"))
    {
        DC -= 5; // give paladins and cavaliers a 5 bonus to beat the DC check
        message += "\t Adding bonus of 5 for paladin or cavalier class\n";
    }

    if(effective_size < 0)
    {
        DC += 20; // small weapons have a +20 DC
        message += "\t Using small weapon, +20 DC\n";
    }

    if(effective_size > 0)
    {
        DC += 10; // large weapons have a +10 DC (lances are mostly medium sized, oddly)
        message += "\t Using large weapon, +10 DC\n";
    }

    if(sizeof(weapon) == 2) // +10 penalty for dual wielding, +5 if they have ambidexterity
    {
        if(objectp(weapon[1]))
        {
            if(weapon[0]->is_weapon() && weapon[1]->is_weapon() && (weapon[0] != weapon[1]))
            {
                if(FEATS_D->usable_feat(tp,"ambidexterity"))
                {
                    DC += 5;
                    message += "\t Dual wielding with ambidexterity, +5 DC\n";
                }
                else
                {
                    DC += 10;
                    message += "\t Dual wielding without ambidexterity, +10 DC\n";
                }
            }
        }
    }

    switch(prof)
    {
    case "simple":

        if(effective_size == 0) { break; } // medium sized simple weapons have no added DC
        DC += 10; // simple weapons of any other size have +10 DC, this stacks with other size penalties
        message += "\t Simple weapon of non-standard size, +10 DC\n";
        break;

    case "martial": // martial weapons currently have no penalties

        break;

    case "exotic":

        if(effective_size == 0) // normal sized exotic weapons have +10 DC
        {
            message += "\t Exotic weapon of normal size, +10 DC\n";
            DC += 10;
            break;
        }
        DC += 20; // non standard sized exotics DC +20
        message += "\t Exotic weapon of non-standard size, +20 DC\n";
        break;
    }


    skill = skill + roll_dice(1,20); // skill level + d20 for final score

    message += "FINAL ROLL: "+skill+"\n";
    message += "FINAL DC CHECK: "+DC+"\n";

    result = skill - DC;

    message += "Skill check: "+result+"\n";

    if(result >= 0)
    {
        message += "  RESULT: Charge Successful\n\n";
        debug_message(message);
        return 1;
    }

    if(result < 0 && result >= -10)
    {
        tell_object(tp,"You almost loose your grip on "+weapon[0]->query_short()+"! Your charge fails!");
        message += "  RESULT: Charge Failed, no negative effect\n\n";
        debug_message(message);
        return 0;
    }

    if(result < -10)
    {
        tell_object(tp,"You loose your grip on "+weapon[0]->query_short()+"!");
        tp->force_me("unwield "+ids[0]+"");
        tp->remove_property("disarm time");
        tp->set_property("disarm time",absolute_value(result));
        message += "  RESULT: Charge Failed, weapon fumbled\n\n";
        debug_message(message);
        return 0;
    }

}


void debug_message(string str)
{
    if(!DEBUG) { return; }
    if(!objectp(tp)) { return; }
    if(!interactive(tp)) { return; }
    if(!stringp(str) || str == "" || str == " ") { return; }

    log_file("charge_log",str);
    return;
}
