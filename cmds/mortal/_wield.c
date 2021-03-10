#include <std.h>
#include <daemons.h>
inherit DAEMON;

//void do_wear_stat(object myplayer, object myitem, string mystat, int mymod);

int cmd_wield(string str)
{
    object ob, *obs;
    string what, hand1, hand2, ok, *wielder, wieldf,ob_quest,*player_quests;
    int size_diff,my_size,its_size,inc,level, free_hands, *tmp,i;
    function f;
    mapping itembonuses;

    if(!str) return notify_fail("Wield what?\n");

    if (TP->query_bound())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    //Jailbirds are not allowed to wield
    if(interactive(TP) && objectp(ETP) && ETP->query_property("IG_Jail"))
    {
        tell_object(TP, "The guards won't allow that here.");
        return 1;
    }

    if((int)TP->query_property("disarm time") > time())
    {
        tell_object(TP,"%^RESET%^%^YELLOW%^You fumble around, unable to properly grasp "
            "the hilt of your weapon!%^RESET%^");
        return 1;
    }

    if(sscanf(str, "%s in %s", what, hand1) != 2)
    {
        what = str;
        inc = 0;
        wielder = this_player()->query_wielding_limbs();
        while(inc < sizeof(wielder))
        {
            if(this_player()->query_weapon(wielder[inc]) || member_array("shield", ((mapping)TP->query_body())[wielder[inc]]["armour"]) != -1 ||  member_array("thiefshield", ((mapping)TP->query_body())[wielder[inc]]["armour"]) != -1)
            {
                inc ++;
                continue;
            }
            else
            {
                if(!hand1) hand1 = wielder[inc];
                free_hands++;
                inc ++;
                continue;
            }
        }
        if(!hand1) return notify_fail("You have no free hands.\n");
    }

    if(!(ob = present(what,TP)) )
    {
        return notify_fail("That is not here.\n");
    }

    if(ob->query_property("level required"))
    {
        if(TP->query_base_character_level() < ob->query_property("level required"))
        {
            tell_object(TP,"You are not strong enough to wield "+ob->query_short());
            return 1;
        }
    }

    if(ob->query_property("quest required") && interactive(TP))
    {
        ob_quest = ob->query_property("quest required");
        ob_quest = FILTERS_D->filter_colors(ob_quest);
        ob_quest = lower_case(ob_quest);
        player_quests = TP->query_quests();
        player_quests += TP->query_mini_quests();
        if(!sizeof(player_quests))
        {
            tell_object(TP,"You have not earned the right to make use of this item");
            return 1;
        }

        for(i=0;i<sizeof(player_quests);i++)
        {
            player_quests[i] = FILTERS_D->filter_colors(player_quests[i]);
            player_quests[i] = lower_case(player_quests[i]);
        }

        if(member_array(ob_quest, player_quests) == -1)
        {
            tell_object(TP,"You have not earned the right to make use of this item");
            return 1;
        }
    }

    if(ob->query_property("master weapon"))
    {
        obs = TP->query_wielded();
        for(i=0;sizeof(obs),i<sizeof(obs);i++)
        {
            if(!objectp(obs[i])) { continue; }
            if(!obs[i]->query_property("master weapon")) { continue; }
            tell_object(TP,"You find it impossible to wield two such mighty weapons at the same time.");
            return 1;
        }
    }

    if(ob->query_property("monsterweapon") && userp(TP))
    {
        ob->remove();
        return 1;
    }

    if(ob->is_bow()) return 0;
    if(ob->query_worn())
    {
        return notify_fail("You can't wield something you're wearing.\n");
    }

    if(ob->query_wielded())
    {
        message("my_action", "You are already wielding that!\n",this_player());
        return 1;
    }

    if(!ob->wieldable() && interactive(TP))
    {
        message("my_action", "Your class will not allow you to wield that!\n",this_player());
        return 1;
    }
    if(TP->query_casting()){ //new fix to stop stacking spells with wear/wield in a round - Nienne, 12/09
      message("my_action", "You are too busy casting a spell to wield that!",this_player());
      return 1;
    }
    its_size = ob->query_size();
    my_size = (int)this_player()->query_size();
    if(my_size >= its_size) size_diff = 0;
    if(my_size < its_size) size_diff = its_size - my_size;
    if(size_diff > 1 &&
         FEATS_D->usable_feat(TP,"titan grip") &&
         !sizeof(TP->query_wielded()))
        size_diff-=1;
    if(size_diff > 1)
    {
        write("This weapon is too big for you, even with both hands!");
        return 1;
    }
    if(size_diff > 0 && free_hands < 2)
    {
        write("You do not have enough free hands!");
        return 1;
    }
    //balance on bonuses
    level = TP->query_highest_level();
    if(ob->query_property("enchantment"))
    //      if(level/5 < ob->query_property("enchantment")) {
    //changing to +1/7 levels

    if (userp(TP) && (level/5 < ob->query_property("enchantment")) )
    {
        message("my_action", "You are not experienced enough to utilize this equipment.",TP);
        return 1;
    }
    obs = TP->query_wielded();
    if(sizeof(obs))
    {
        tmp = obs->query_property("lance");
        tmp -= ({0});
        if(sizeof(tmp))
        {
            tell_object(TP, "You cannot dual wield while using a lance.");
            return 1;
        }
    }
    if(sizeof(obs) && ob->query_property("lance")) { tell_object(TP, "You cannot dual wield with a lance."); return 1; }
    wieldf = ob->query_wield();

    if(size_diff > 0)
    {
        str = hand1;
        if(sscanf(str, "%s and %s", hand1, hand2) != 2)
        {
        //            message("my_action", "You must wield such a weapon with two hands.\n",
        //              this_player());
        //            return 1;
            hand1 = "right hand";
            hand2 = "left hand";
        }

        if(hand1 == hand2)
        {
            message("my_action","Ummm care to try again?",this_player());
            return 1;
        }
        if(free_hands < 2)
        {
            write("You do not have enough free hands!");
            return 1;
        }
        f = (:call_other,ob,wieldf:);
        if(ob->query_property("fwield"))
        {
            if(!((*f)()))
            {
                return 1;
            }
        }
		ok = (string)this_player()->equip_weapon_to_limb(ob, hand1, hand2);
    }


    else
    {
        if(sscanf(hand1, "%s and %s", str, hand2) == 2)
        {
            message("my_action", "You must only use one hand to wield that "+
                "weapon.", this_player());
            return 1;
        }

        f = (:call_other, ob, wieldf:);
        if(ob->query_property("fwield"))
        {
            if(!((*f)()))
            {
                return 1;
            }
        }
     	ok  = (string)this_player()->equip_weapon_to_limb(ob,hand1,0);
    }

    if(ok)
    {
        message("my_action", ok, this_player());
        return 1;
    }

    if (stringp(wieldf) && !ob->query_property("fwield")) {
        message("my_action", wieldf, this_player());
    }else {
        if (!this_player()->query_property("silent_wield")) {
            message("my_action", "You wield " + ob->query_short() + ".", this_player());
        }
    }
    if (!this_player()->query_property("silent_wield")) {
        if (objectp(ETP)) {
            message("other_action", (string)this_player()->query_cap_name() +
            " wields " + ob->query_short() + ".", environment(this_player()), ({ this_player()}));
        }
    }
    //           " wields #^#(:\"" + file_name(ob) +"\",\"query_short\":)#^#.", environment(this_player()),
	POISON_D->is_object_poisoned(ob, TP, "wield", 1);
    ob->set_wielded(this_player());
    ob->set_limbString(" (wielded in " + hand1 + (hand2 ? " and "+hand2+")" : ")"));

    // https://shadowgate.org/git/shadowgate/shadowgate/issues/339

    if (ob->query_size() > 1) {
       ob->reset_hidden_seen();
    }

    //   new function for running stat adjustments on item wear.
/*    if((int)ob->query("strbonus")) do_wear_stat(TP,ob,"strbonus",(int)ob->query("strbonus"));
    if((int)ob->query("dexbonus")) do_wear_stat(TP,ob,"dexbonus",(int)ob->query("dexbonus"));
    if((int)ob->query("conbonus")) do_wear_stat(TP,ob,"conbonus",(int)ob->query("conbonus"));
    if((int)ob->query("intbonus")) do_wear_stat(TP,ob,"intbonus",(int)ob->query("intbonus"));
    if((int)ob->query("wisbonus")) do_wear_stat(TP,ob,"wisbonus",(int)ob->query("wisbonus"));
    if((int)ob->query("chabonus")) do_wear_stat(TP,ob,"chabonus",(int)ob->query("chabonus"));
*/
    // new code for item bonus properties to replace all existing props/funcs. Nienne, 7/12.
	if(itembonuses = ob->query_item_bonuses()) ob->run_item_bonuses("equip",TP,itembonuses);

    if((string)ob->query_prof_type() == "magic weapons")
    {
        TP->set_skill("magic weapons",100);
    }

    if((string)ob->query_prof_type() == "unknown")
    {
        tell_object(TP,"Error: Please contact a wiz.. weapon type is unknown.");
    }

    else if(ob->query_prof_type() && !TP->query_skill(ob->query_prof_type()))
    {
        TP->add_skill(ob->query_prof_type(),1);
    }

    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

wield - hold a thing or weapon

%^CYAN%^SYNOPSIS%^RESET%^

wield %^ORANGE%^%^ULINE%^ITEM%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will attempt to wield the given %^ORANGE%^%^ULINE%^ITEM%^RESET%^. Not all items are good weapons.

N.B. Shields are worn, not weld, as they are armour pieces. Attempt to wield shield as a weapon will turn it into simple blunt weapon and won't help with your defenses.

%^CYAN%^SEE ALSO%^RESET%^

unwield, wear, remove, inv, eq, limbs, look
");
}
