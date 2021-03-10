#include <std.h>
#include <move.h>

#define STEAL_BONUS (int)who->query_highest_level()-(int)TP->query_highest_level() + 10

inherit DAEMON;


void flag_stolen(object obj, int difficulty);


int cmd_strip(string str) {
    object who,ob,money_ob;
    mapping currs;
    object *inv;
    int i,res, gold;
    string tmp, whom,what;

    if(!str) {
        return notify_fail("Strip whom of what?\n");
    }


    if(sscanf(str, "%s of %s",whom,what) != 2) {
        whom = str;
        what = "all";
    }

    if(TP->query_bound()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(sizeof(TP->query_attackers())) {
        return notify_fail("You are too busy right now.\n");
    }


    if (!(who = present(whom, ETP)) ||
        (avatarp(who) && who->query_true_invis())) {
        return notify_fail(capitalize(whom) + " is not here.\n");
     }

    if(!TP->ok_to_kill(who)) return notify_fail("Supernatural forces prevent you from doing that.\n");
    if(!who->query_bound() && !who->query_unconscious()) {
        return notify_fail("That person will not be happy with that.\n");
    }
    if(what == "all") {
        return notify_fail("Strip all has been disabled as it allowed for to much unrealistic abuse.\n");

        inv = all_inventory(who);
        for(i=0;i<sizeof(inv); i++ ) {
            ob = inv[i];
            tmp = (string)ob->query_short();
            if(ob->drop()) continue;
            if(ob->is_cursed()) continue;
            if(ob->query_property("monsterweapon")) continue;
            res = (int)ob->move(environment(TP));
            ob->set_property("died time",time());
            if(res == MOVE_OK) {
                tell_room(ETP,TPQCN+" takes "+tmp+" from "+who->query_cap_name()+" and dumps it on the ground.",({TP,who}));
            }

            flag_stolen(ob, STEAL_BONUS);//ob->set_property("stolen",([TPQN:(["difficulty":STEAL_BONUS,"max value":ob->query_value()])]));
        }

        money_ob = new("/std/obj/coins");
        currs = who->query_currencies();
        for(i=0, tmp= sizeof(currs); i<tmp; i++) {
            money_ob->set_money(currs[i], who->query_money(currs[i]));
            who->add_money(currs[i],-(int)(who->query_money(currs[i])));

        }
        gold = currs["gold"] + currs["platinum"]*5 + currs["electrum"]/2 + currs["silver"]/10 + currs["copper"]/100;
        TP->set("stolen money",(int)TP->query("stolen money")+gold);
        money_ob->move(environment(TP));
        money_ob->set_property("died time",time());
        tell_object(TP,"%^BOLD%^You strip "+who->query_cap_name()+" of all "+who->query_possessive()+" current possessions.");
        if(!who->query_unconscious()) {
            tell_object(who,"%^BOLD%^"+TPQCN+" strips you of your worldly possessions.");
        }
    }
    else {
        if(what == "money") {

            money_ob = new("/std/obj/coins");
            currs = who->query_currencies();
            for(i=0, tmp= sizeof(currs); i<tmp; i++) {
                gold = who->query_money(currs[i]);
                money_ob->set_money(currs[i], who->query_money(currs[i]));
                who->add_money(currs[i],-(int)(who->query_money(currs[i])));

                switch (currs[i]){
                    case "gold":
                        gold = gold;
                        break;
                    case "silver":
                        gold = gold/10;
                        break;
                    case "copper":
                        gold = gold/100;
                        break;
                    case "platinum":
                        gold = gold*5;
                        break;
                    case "electrum":
                        gold = gold/2;
                        break;
                }
                TP->set("stolen money",(int)TP->query("stolen money")+gold);
            }
            money_ob->move(TP);

            tell_object(TP,"You take all the money from "+who->query_cap_name()+".");
            tell_room(ETP,TPQCN+" takes all the money from "+who->query_cap_name()+".",({TP,who}));

            if(!who->query_unconscious()) {
                tell_object(who,"%^BOLD%^"+TPQCN+" takes all the money from you.");
            }
            return 1;
        }
        if(!(ob = present(what,who))) {
            tell_object(TP,"That item is not currently on "+who->query_cap_name()+".\n");
            return 1;
        }

        tmp = ob->query_short();
/* per typo report was coming back - can't pry that from $&$vendel$&
        if(ob->drop()) return notify_fail("You can't pry that from "+who->query_cap_name()+".\n");
        if(ob->is_cursed()) return notify_fail("You can't pry that from "+who->query_cap_name()+".\n");
        if(ob->query_property("monsterweapon")) return notify_fail("You can't pry that from "+who->query_cap_name()+".\n");
so changing to the following - Styx  5/28/03
*/
        if(ob->drop() || ob->is_cursed() || ob->query("no steal") || ob->query_property("monsterweapon")) {
	    tell_object(TP, "You can't pry that from "+who->query_cap_name()+".");
	    return 1;
	}
// brief addition for Amasaeele aura plot
        if(base_name(ob) == "/d/avatars/myrkul/chaosaura2") {
	    tell_object(TP, "The aura merely slips through your fingers whenever you try to remove it from "+who->query_cap_name()+".");
	    return 1;
	}

        res = (int)ob->move(TP);

        if(res == MOVE_OK) {
            tell_object(TP,"You take "+tmp+" from "+who->query_cap_name()+".");
            tell_room(ETP,TPQCN+" takes "+tmp+" from "+who->query_cap_name()+".",({TP,who}));

            if(!who->query_unconscious()) {
                tell_object(who,"%^BOLD%^"+TPQCN+" takes "+tmp+" from you.");
            }
        }
        else {
            tell_object(TP,"You cannot carry "+tmp+".");
        }

        flag_stolen(ob, STEAL_BONUS);//ob->set_property("stolen",([TPQN:(["difficulty":STEAL_BONUS,"max value":ob->query_value()])]));
    }
    return 1;
}


void flag_stolen(object obj, int difficulty) {
    int i;

    obj->set_property("stolen",([TPQN:(["difficulty":difficulty,"max value":obj->query_value()])]));
    if(obj->is_bag()) {
        for(i = 0;i< sizeof(all_inventory(obj));i++) {
            flag_stolen(all_inventory(obj)[i],difficulty);
        }
    }
}


void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

strip - make someone naked

%^CYAN%^SYNOPSIS%^RESET%^

strip %^ORANGE%^%^ULINE%^TARGET%^RESET%^ [of %^ORANGE%^%^ULINE%^ITEM%^RESET%^|money]

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument removes all items from %^ORANGE%^%^ULINE%^TARGET%^RESET%^. If you specify an %^ORANGE%^%^ULINE%^ITEM%^RESET%^, will remove only that %^ORANGE%^%^ULINE%^ITEM%^RESET%^. To rid someone of money, append suffix \"of money\".

Stirpping will move items into your inventory.

This is ment to be an RP tool. Please consider some common sense and ooc fairness when doing so.

%^CYAN%^SEE ALSO%^RESET%^

get, bind, blindfold, gag, hit, pkilling, rules
"
         );
}
