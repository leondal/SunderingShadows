// _pp.c
// Rogue ability
// created 04 November 1992 by Descartes of Borg

#include <std.h>
inherit DAEMON;


#define INVIS_PENALTY 75
#define INVIS_CHECK_DIE 20

void check_caught(int roll,object target, int sLevel);
void do_caught(object victim);

int cmd_pp(string str) {
    object ob;
    string amt_string;
    int steal, roll, sLevel,i, amt;
    int platinum, gold, electrum, silver, copper;

    if (TP->query_ghost()) {
    	notify_fail("You cannot do that in your immaterial state.\n");
    	return 0;
    }
    if (TP->query_bound() || TP->query_tripped()) {
	    TP->send_paralyzed_message("info",TP);
	    return 1;
    }
    if (!str) {
	    notify_fail("Pick whom?\n");
	    return 0;
    }
    if (TP->query_current_attacker()) {
	    notify_fail("You can't do that while in combat!\n");
	    return 0;
    }
    
    ob = present(str, ETP);

    if (!ob) ob = parse_objects(ETP, str);
    if (!ob) {
	    notify_fail("No "+str+" here!\n");
	    return 0;
    }
    if (!living(ob)) {
	    notify_fail(capitalize(str)+" is not a living thing!\n");
	    return 0;
    }
    if (wizardp(ob)) {
	    notify_fail("That is not adviseable.\n");
	    return 0;
    }
    if (ob->is_player() && !interactive(ob)) return 0;
    if (ob==TP) {
	    notify_fail("You cannot pick your own purse!\n");
	    return 0;
    }
    if(ETP->query_property("no steal")) {
        notify_fail("A magic force prevents you from doing that!\n");
        return 0;
    }
    if(ob->query_property("no steal")) {
        notify_fail((string)ob->query_cap_name()+" cannot be stolen from!\n");
        return 0;
    }
    if (!TP->ok_to_kill(ob)) return notify_fail("Supernatural forces prevent you.\n");
    if ((ob->is_player()) && (ob->ok_to_kill(TP))){
        write("You cannot steal with a NoPK flag\n");
        return 1;
    }

    if (!TP->is_ok_armour("mage")) steal -= 30; // Mages can wear clothing magic and nothing at all
    else steal += 5;

    if (ob->query_invis()) steal -= INVIS_PENALTY;
    /* Display messages */

    roll = random(100)+1;
    //    tell_object(TP,"x = "+roll+" steal = "+steal); */
    steal = TP->query_skill("thievery") + roll_dice(1,20);
    if(sizeof(TP->query_armour("torso"))) steal += TP->skill_armor_mod(TP->query_armour("torso"));
    roll = ob->query_skill("perception") + roll_dice(1,20);

    if (roll>steal || (TP->get_static("caught") &&  time() - (int)((mapping)TP->get_static("caught"))[ob] <= 150)) {
	    write("You utterly fail in your attempt to pick from "+ob->query_cap_name()+".");
	    check_caught(roll,ob,steal);
	    return 1;
	}

	platinum = (int)ob->query_money("platinum");
	gold = (int)ob->query_money("gold");
	electrum = (int)ob->query_money("electrum");
	silver = (int)ob->query_money("silver");
	copper = (int)ob->query_money("copper");

    if (!platinum && !gold && !electrum && !silver && !copper) {
	    tell_object(TP,""+ob->query_cap_name()+" is flat broke!\n");
	    return 1;
	}

	platinum = (steal*(platinum/10))/100;
	gold = (steal*(gold/10))/100;
	electrum = (steal*(electrum/10))/100;
	silver = (steal*(silver/10))/100;
	copper = (steal*(copper/10))/100;

    if (!platinum && !gold && !silver && !electrum && !copper) {
	    write("You fail to get anything from "+ob->query_cap_name()+"'s purse.");
	} 
    else {
	    ob->add_money("platinum", -platinum);
	    ob->add_money("gold", -gold);
	    ob->add_money("electrum", -electrum);
	    ob->add_money("silver", -silver);
	    ob->add_money("copper", -copper);
	    TP->add_money("platinum", platinum);
	    TP->add_money("gold", gold);
	    TP->add_money("electrum", electrum);
	    TP->add_money("silver", silver);
	    TP->add_money("copper", copper);
	    write("You pick some money from "+ob->query_cap_name()+
            "'s purse.");
        amt = gold + platinum*5 + electrum/2 + silver/10 + copper/100;
        amt_string = "gold";
        if(!amt) {
            amt = electrum + silver / 5 + copper / 50;
            amt_string = "electrum";
        }
        if(!amt) {
            amt = silver + copper / 10;
            amt_string = "silver";
        }
        if(!amt) {
            amt = copper;
            amt_string = "copper";
        }

	    write("It amounts to "+amt+" "+amt_string+" in various coins.");
    }

	//if (interactive(ob))
	log_file("player/theft", TPQN+" stole "+gold+" gold from "+ob->query_name()+" on "+ctime(time())+"\n");
	i = check_caught(roll,ob, sLevel);
	if(TP->query("stolen money")){
	    TP->set("stolen money",(int)TP->query("stolen money")+amt);
	} 
    else {
	    TP->set("stolen money",amt);
	}
	return 1;
}

void help() {
    write(
"%^CYAN%^NAME%^RESET%^

pp - pickpocket someone

%^CYAN%^SYNOPSIS%^RESET%^

pp %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will attempt to steal some money from %^ORANGE%^%^ULINE%^TARGET%^RESET%^. If %^ORANGE%^%^ULINE%^TARGET%^RESET%^ discovers you attempt, they will be upset at you.

%^CYAN%^SEE ALSO%^RESET%^

stealth, steal, spy, look, glance, pkilling, flee"
        );
}

void check_caught(int roll, object target, int sLevel){
	int test;
	int weight;
	int intox,condition,busy,bonus;
	string *pkills;
    object * inven;
    int i;


	intox = (((int)target->query_intox())/35) - ((int)TP->query_intox())/35;
	condition = (100- (int)target->query_condition_percent()) - (100- (int)TP->query_condition_percent());
	busy = (5 * ( sizeof(all_living(ETP)) -2) ) - 10;
	bonus = intox + condition + busy + sLevel;
	test = 50 + ((int)target->query_highest_level() - bonus);
	if ((100 - roll)<test) {
        TP->set_hidden(0);
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
	    tell_room(environment(TP),"You see "+target->query_cap_name()+" catch "+TPQCN+" with a hand in "+target->query_possessive()+" pocket.",({TP,target}));
        inven = all_living(ETP);
        for(i=0;i<sizeof(inven);i++){
	        if(objectp(inven[i])) inven[i]->check_caught(TP,target,roll);
        }
	    if (!interactive(target)) target->kill_ob(TP,0);
	    else
		    log_file("player/theft", TPQN+"("+sLevel+") was caught stealing from "+target->query_name()+"("+target->query_lowest_level()+") on "+ctime(time())+"\n");
        if (TP->is_singleClass()) {
            TP->set_disable(2,target);
        } 
        else {
            TP->set_disable(2*sizeof(TP->query_classes()),target);
        }
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

