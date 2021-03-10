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
#define WEIGHT_PENALTY 20
#define INVIS_PENALTY 75
#define WIELD_PENALTY 50
#define WORN_PENALTY 75

#define INVIS_CHECK_DIE 20
inherit DAEMON;

void check_caught(int roll, object target, object ob, int sLevel);
void do_caught(object victim);

int cmd_plant(string str) {
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

/*   if(!TP->is_class("thief") && !TP->is_class("bard")) {
      notify_fail("Too bad you don't know how to do that.\n");
      return 0;
   }*/

    if (!str) {
        notify_fail("Plant what on whom?\n");
        return 0;
    }
    if (TP->query_disable()) return 1;

    if (sscanf(str, "%s on %s", what, whom) != 2) {
        notify_fail("Plant what on whom?\n");
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

//    TP->set_disable();

    if (wizardp(victim)) {
        tell_object(victim,TPQCN+" just tried to plant something on you... break "+TP->query_possessive()+" arms.\n");
        notify_fail(victim->query_cap_name()+" is going to hurt you when "+victim->query_subjective()+" gets this message.\n");
        return 0;
    }

   if (victim == TP) {
      notify_fail("Plant on yourself?\n");
      return 0;
   }

    if (victim->query_property("no steal")) {
        notify_fail((string)victim->query_cap_name()+" cannot be planted on!\n");
        return 0;
    }

//    if ((total_light(TP)+TP->query_sight_bonus()) < -1) {
   if (TP->light_blind(-1)) {
  notify_fail(TP->light_blind_fail_message(TP->light_blind(-1))+"\n");
        return 0;
    }

    ob = present(what, TP);

    if (!ob) {
        notify_fail("You do not have that!\n");
        return 0;
    }
    if (ob->drop()) {
        notify_fail("You cannot plant that!\n");
        return 0;
    }

   if(ETP->query_property("no steal")) {
      notify_fail("A magic force prevents you from doing that!\n");
      return 0;
   }

    if (ob->query_property("no steal")) {
        write((string)victim->query_cap_name()+"'s "+(string)ob->query_name()+" cannot possibly be planted on.");
        return 1;
    }

/* Calculations */
    steal = TP->query_skill("thievery") + roll_dice(1,20);
    if(sizeof(TP->query_armour("torso"))) steal += TP->skill_armor_mod(TP->query_armour("torso"));

    if (victim->query_invis()) steal -= INVIS_PENALTY;
    if ((int)ob->query_weight() > 50 ) steal -= WEIGHT_PENALTY;

    if (ob->query_wielded() || ob->query_worn()) {
        notify_fail("That would be impossible!\n");
        return 0;
    }

  if (!TP->is_singleClass()) {
     TP->set_disable(15,victim);
   } else {
     TP->set_disable(5,victim);
   }
/* Display messages */
    x = victim->query_skill("perception") + roll_dice(1,20);
    if (x<steal && (!TP->get_static("caught") ||  time() - (int)((mapping)TP->get_static("caught"))[victim] > 150)) {
        write("You successfully plant "+ob->query_name()+" on "+victim->query_cap_name()+".\n You are not sure if anyone noticed.");
        if (ob->move(victim)) {
            write(victim->query_cap_name()+" cannot carry that!\nThe plant fails.");
        }
        check_caught(x,victim,ob,steal);
        if (interactive(victim))
            log_file("player/theft", TPQN+"("+TP->query_level()+") planted "+ob->query_short()+" on "+victim->query_name()+"("+victim->query_lowest_level()+") on "+ctime(time())+"\n");
        return 1;

    } else {
        if (TP->get_static("caught") && (int)((mapping)TP->get_static("caught"))[victim] - time() < 150) {
            x=0;
        }
        write("You fail to plant the "+ob->query_name()+" on "+victim->query_cap_name()+", but you are unsure if it went unnoticed.");
        check_caught(x,victim,ob,steal);
        return 1;
    }

}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

plant - plant something

%^CYAN%^SYNOPSIS%^RESET%^

plant %^ORANGE%^%^ULINE%^ITEM%^RESET%^ on %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Plant gives a thief the ability to stealthily plant an item on another person. Sometimes the victim or others might notice, or sometimes no one will notice at all. It all depends on your ability to steal, the lighting, and other factors.

%^CYAN%^SEE ALSO%^RESET%^

stealth, give, spy, steal, pp, pkilling
");
}
void check_caught(int roll, object target, object ob, int sLevel){
    int test;
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
      if(TP->query_magic_hidden()) {
if ((TP->is_thief()) && TP->is_singleClass())
  bonus = 5;
else
  bonus = 0;
if ((int)target->query_stats("wisdom") > (random(INVIS_CHECK_DIE) + bonus))
        {
	  TP->force_me("appear");
	  TP->set_magic_hidden(0);
	}
      }
        tell_object(target,"You catch "+TPQCN+" with "+TP->query_possessive()+" hand in your pocket.\n");
        //tell_object(target,capitalize(TP->query_subjective())+" was stealing from you.\n");
        tell_object(TP,"You get caught.");
        tell_room(environment(TP),"You see "+target->query_cap_name()+" catch "+TPQCN+" with a hand in "+target->query_possessive()+" pocket.",({TP,target}));

        if (!interactive(target)) {
            target->kill_ob(TP, 0);
        }else {
            log_file("player/theft", TPQN + "(" + sLevel + ") was caught stealing " + ob->query_short() + " from " + target->query_name() + "(" + target->query_lowest_level() + ") on " + ctime(time()) + "\n");
        }
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
}

void do_caught(object victim){

    TP->set_static("caught",([victim:time()]));

}
