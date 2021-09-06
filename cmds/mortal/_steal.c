/*  _steal.c
 *  Rogue ability
 *  coded by Descartes of Borg October 1992
 *  small modifications by Hanse November 1992
 *  changed to make stealing harder for non-rogues and to allow
 *  the stealing of wielded/worn objects by powerful rogues
 *  by Gregon October 1993
 *  Heavily revised by Bohemund March 1994
 *    - check for available light
 *    - removed useless variables
 *    - added a function to handle the moving of the stolen object
 *    - cleaned up messages
 *    - checked weight of item being stolen (heavier = harder)
 *    - revised the way wielded/worn items are stolen (monster now
 *      attacks when the player fails)
 *    - alignment is calculated (randomly 1-10) depending on the
 *      alignment of the victim (i.e. stealing from good beings
 *      makes you more evil and stealing from evil beings makes
 *      you good)
 *    - added defines for easier configuration
 *  Slightly modified by Bohemund March 1994
 *    - check if monster does not allow stealing
 *    - neaten up a string or two
 */

#include <std.h>
#define WEIGHT_PENALTY 2
#define INVIS_PENALTY 2
#define WIELD_PENALTY 50
#define WORN_PENALTY 75
#define INVIS_CHECK_DIE 25 // the actual max of a stat

inherit DAEMON;

int check_caught(int roll, object target, object ob, int sLevel);
void do_caught(object victim);
void flag_stolen(object obj, int difficulty);


int cmd_steal(string str) {
    object *inv, victim, ob;
    string what, whom;
    int i, skip, which, steal, x, align_formula,sLevel;

/* Various checking */
    if (TP->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_tripped()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!str) {
        notify_fail("Steal what from whom?\n");
        return 0;
    }
    if (TP->query_disable()) return 1;
    if (sscanf(str, "%s from %s", what, whom) != 2) {
        notify_fail("Steal what from whom?\n");
        return 0;
    }
    if (TP->query_current_attacker()) {
        notify_fail("You cannot do that while in combat!\n");
        return 0;
    }
    victim = present(whom, ETP);
    if (!victim) {
        notify_fail(capitalize(whom)+" is not here!\n");
        return 0;
    }
    if (!living(victim)) {
        notify_fail(capitalize(whom)+" is not a living thing!\n");
        return 0;
    }
    if (victim->is_player() && !interactive(victim)) {
        notify_fail("You cannot steal from link-dead players.\n");
        return 0;
    }
    if (!TP->ok_to_kill(victim)) return notify_fail("Super natural forces prevent you.\n");
    if ((victim->is_player()) && (!victim->ok_to_kill(TP))){
        write("You cannot steal with a NoPK flag\n");
        return 1;
    }

//    TP->set_disable(2*sizeof(TP->query_classes()),victim);

    if (wizardp(victim)) {
        tell_object(victim,TPQCN+" just tried to steal from you... break "+TP->query_possessive()+" arms.\n");
        notify_fail(victim->query_cap_name()+" is going to hurt you when "+victim->query_subjective()+" gets this message.\n");
        return 0;
    }

   if(victim == TP) {
        notify_fail("Steal from yourself?\n");
        return 0;
    }

//    if ((total_light(TP)+TP->query_sight_bonus()) < -1) {
    if (TP->light_blind(-1)) {
        notify_fail(TP->light_blind_fail_message(TP->light_blind(-1))+"\n");
        return 0;
    }


    ob = present(what, victim);

    if(victim->query_property("shapeshifted"))
    {
        if((!ob->id("kitxyz")) && (!ob->id("band")) )
        {
            tell_object(TP,victim->QCN+" doesn't have that.");
            return 1;
        }
    }

    if (!ob) {
        inv = all_inventory(victim);
        if (sscanf(what, "%s %d", what, which) != 2) {
            notify_fail(capitalize(whom)+" does not have that!\n");
            return 0;
        }
        for (i=0, skip=0; i<sizeof(inv) && !ob; i++) {
            if (inv[i]->id(what)) {
                skip ++;
                if (skip == which) ob = inv[i];
            }
        }
        if (!ob) {
            notify_fail(capitalize(whom)+" does not have that!\n");
            return 0;
        }
    }
    if (!ob->get()) {
        notify_fail("You cannot steal that!\n");
        return 0;
    }
    if (victim->query_property("hidden inventory") || ob->query_property("no steal") || ob->query_property("plot_item") || ob->query_property("soulbound")) {
        write((string)victim->query_cap_name()+"'s "+(string)ob->query_name()+" cannot possibly be stolen.");
        return 1;
    }
    if (ETP->query_property("no steal")) {
        notify_fail("A magic force prevents you from doing that!\n");
        return 0;
    }
    if (victim->query_property("no steal")) {
        notify_fail((string)victim->query_cap_name()+" cannot be stolen from!\n");
        return 0;
    }
    if (ob->query_wielded() || ob->query_worn()) {
        notify_fail("That would be impossible!\n");
        return 0;
    }
    if (TP->is_singleClass()) {
        TP->set_disable(2,victim);
    } 
    else {
        TP->set_disable(2*sizeof(TP->query_classes()),victim);
    }

/* Calculations */
    steal = TP->query_skill("thievery") + roll_dice(1,20);
    if(sizeof(TP->query_armour("torso"))) steal += TP->skill_armor_mod(TP->query_armour("torso"));

    if (victim->query_invis()) steal -= INVIS_PENALTY;
    if ((int)ob->query_weight() > 50 ) steal -= WEIGHT_PENALTY;

/* Display messages */
    x = victim->query_skill("perception") + roll_dice(1,20);
    //tell_object(TP,"x = "+x+" steal = "+steal);
    if (x<steal && (!TP->get_static("caught") ||  time() - (int)((mapping)TP->get_static("caught"))[victim] > 150)) {
        write("You successfully steal "+victim->query_cap_name()+"'s "+
            ob->query_name()+".\nYou are not sure if anyone noticed.");
        if (ob->move(TP)) {
            write("You cannot carry that!\nYou drop "+ob->query_name()+".");
            say(TPQCN+" drops "+ob->query_name()+".", TP);
            ob->move(ETP);
        }
        i = check_caught(x,victim,ob,steal);
        if (interactive(victim)){
        log_file("player/theft", TPQN+"("+TP->query_level()+") stole "+ob->query_short()+" from "+victim->query_name()+"("+victim->query_lowest_level()+") on "+ctime(time())+" with difficulty "+i+" at "+environment(TP)+"\n");
        }
	else{
       log_file("stealing", TPQN+"("+TP->query_level()+") stole "+ob->query_short()+" from "+victim->query_name()+"("+victim->query_lowest_level()+") on "+ctime(time())+" with difficulty "+i+" at "+environment(TP)+"\n");
        }
        flag_stolen(ob,i);//ob->set_property("stolen",([TPQN:(["difficulty":i,"max value":ob->query_value()])]));
        return 1;

    } 
    else {
        if (TP->get_static("caught") && (int)((mapping)TP->get_static("caught"))[victim] - time() < 150) {
            x=0;
        }
        write("You fail to steal "+victim->query_cap_name()+"'s "+
            ob->query_name()+", but you are unsure if it went unnoticed.");
        check_caught(x,victim,ob,steal);
        return 1;
    }
}

void flag_stolen(object obj, int difficulty){
    int i;

    obj->set_property("stolen",([TPQN:(["difficulty":difficulty,"max value":obj->query_value()])]));
    if (obj->is_bag()) {
        for (i = 0;i< sizeof(all_inventory(obj));i++) {
            flag_stolen(all_inventory(obj)[i],difficulty);
        }
    }
}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

steal - optimize someone's intentory

%^CYAN%^SYNOPSIS%^RESET%^

steal %^ORANGE%^%^ULINE%^ITEM%^RESET%^ from %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will attempt to repossess %^ORANGE%^%^ULINE%^ITEM%^RESET%^ in %^ORANGE%^%^ULINE%^TARGET%^RESET%^'s inventory into your inventory. Success of this action depends on your thievery skill, lightning condition, targets perception and some other factors. Stolen item will be marked as such and can be then fenced out at thieves guild for guild credits, or sold for money.

%^CYAN%^SEE ALSO%^RESET%^

thievery, perception, skills, pp, glance, spy, thief, stab, stealth
"
        );
}

int check_caught(int roll, object target, object ob, int sLevel){
    int test;
    int i;
    object * inven;
    int weight;
    int intox,condition,busy,bonus;
    string *pkills;


    intox = (((int)target->query_intox())/35) - ((int)TP->query_intox())/35;
    condition = (100- (int)target->query_condition_percent()) - (100- (int)TP->query_condition_percent());
    busy = (5 * ( sizeof(all_living(ETP)) -2) ) - 10;
    bonus = intox + condition + busy + sLevel;
    //write("bonus = "+bonus);
    test = 50 + ((int)target->query_highest_level() - bonus);
    //write("test = "+test);
    if ((100 - roll)<test) {
        TP->set_hidden(0);
// I know I said I didn't want this to happen -- glad my opinion means something - T
        if(TP->query_magic_hidden()) {
            if (TP->is_thief()) bonus = 5;
            else bonus = 0;
            if ((int)target->query_stats("wisdom") > (random(INVIS_CHECK_DIE) + bonus)) {
                TP->force_me("appear");
                TP->set_magic_hidden(0);
            }
        }

        tell_object(target,"You catch "+TPQCN+" with "+TP->query_possessive()+" hand in your pocket.\n");
        //tell_object(target,capitalize(TP->query_subjective())+" was stealing from you.\n");
        tell_object(TP,"You get caught.");
        tell_room(environment(TP),"You see "+target->query_cap_name()+" catch "+TPQCN+" with a hand in "+target->query_possessive()+" pocket.",({TP,target}));     inven = all_living(ETP);
        for(i=0;i<sizeof(inven);i++){
            if(objectp(inven[i])) inven[i]->check_caught(TP,target,roll);
        }

        if (!interactive(target)) target->kill_ob(TP,0);
        else
            log_file("player/theft", TPQN+"("+sLevel+") was caught stealing "+ob->query_short()+" from "+target->query_name()+"("+target->query_lowest_level()+") on "+ctime(time())+"\n");
        if (ob->query_weight() < 1)
            weight = 1;
        else
            weight = ob->query_weight();
        if (environment(ob) == TP && (int)TP->query_stats("dexterity") < (random(20) + weight/10)) {
            TP->force_me("drop "+((string *)ob->query_id())[0]);
        }
        TP->set_paralyzed(2,"You have been caught!");
        if (interactive(TP)) {
            pkills = TP->query_pkilled();
            if (member_array(target->query_name(),pkills) == -1) {
                pkills += ({target->query_name()});
                TP->set_pkilled(pkills);
            }
        }
        do_caught(target);
    }
    return test;
}

void do_caught(object victim){

    TP->set_static("caught",([victim:time()]));

}

