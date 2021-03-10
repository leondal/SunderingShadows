#include <std.h>
#include <daemons.h>
#include <objects.h>

inherit DAEMON;

//void do_wear_stat(object myplayer, object myitem, string mystat, int mymod);

int cmd_wear(string str)
{
    mixed* limbs;
    string ret, what, where, wear, unwear, ob_quest, * player_quests;
    int i, j, level, quiet, ultimate, active_feat;
    object ob, * obs;
    mapping itembonuses;

    if (!objectp(TP)) {
        return 0;
    }
    quiet = (int)TP->query_property("silent_equip");
    ultimate = (int)TP->query_property("ultimate_equip");
    if (!str || !stringp(str)) {
        return notify_fail("Wear what?\n");
    }

    if (!ultimate && TP->query_bound()) {
        if (!quiet) {
            TP->send_paralyzed_message("info", TP);
        }
        return 1;
    }

    // Allow wearing by filename
    if (ultimate && (strsrch(str, "#") != -1)) {
        if (!(ob = present(find_object(str), TP))) {
            if (!(sscanf(str, "%s on %s", what, where) != 2 && stringp(what) && (!(ob = present(find_object(what), TP)) /* && parse_objects(TP,what) != ob*/))) {
                notify_fail("You don't have that!\n");
                return 0;
            }
        }
    }else {
        if (!(ob = present(str, TP))) {
            if (!(sscanf(str, "%s on %s", what, where) != 2 && stringp(what) && (!(ob = present(what, TP)) && parse_objects(this_player(), what) != ob))) {
                notify_fail("You don't have that!\n");
                return 0;
            }
        }
    }

    if (ob->query_type() == "ring" && ((member_array("left hand", ob->query_limbs()) != -1) || (member_array("right hand", ob->query_limbs()) != -1))) {
        if (ob->query_property("enchantment") || ob->query_property("ring of protection") || ob->id("ring of protection")) {
            obs = TP->all_armour();
            for (i = 0; sizeof(obs), i < sizeof(obs); i++) {
                if (!objectp(obs[i])) {
                    continue;
                }
                if (obs[i]->query_type() != "ring") {
                    continue;
                }
                if ((member_array("left hand", obs[i]->query_limbs()) == -1) && (member_array("right hand", obs[i]->query_limbs()) == -1)) {
                    continue;
                }
                if (obs[i]->query_property("enchantment") || obs[i]->query_property("ring of protection") || obs[i]->id("ring of protection")) {
                    tell_object(TP, "You are already wearing enchanted gear on your hand and can not wear another one.");
                    return 1;
                }
            }
        }
    }

    if ((int)ob->query_property("level required")) {
        if ((int)TP->query_base_character_level() < (int)ob->query_property("level required")) {
            tell_object(ETO, "You are not strong enough to wear " + ob->query_short());
            return 1;
        }
    }

    if (ob->query_property("quest required") && interactive(TP)) {
        ob_quest = ob->query_property("quest required");
        ob_quest = FILTERS_D->filter_colors(ob_quest);
        ob_quest = lower_case(ob_quest);
        //tell_object(find_player("saide"), "ob_quest = "+ob_quest);
        player_quests = TP->query_quests();
        player_quests += TP->query_mini_quests();
        if (!sizeof(player_quests)) {
            tell_object(TP, "You have not earned the right to make use of this item");
            return 1;
        }

        for (i = 0; i < sizeof(player_quests); i++) {
            player_quests[i] = FILTERS_D->filter_colors(player_quests[i]);
            player_quests[i] = lower_case(player_quests[i]);
            //tell_object(find_player("saide"), "player_quests[i] "+player_quests[i]);
        }

        if (member_array(ob_quest, player_quests) == -1) {
            tell_object(TP, "You have not earned the right to make use of this item");
            return 1;
        }
    }

    if (TP->query_property("shapeshifted")) {
        if ((base_name(ob) != "/d/azha/obj/gmr_ring") && (base_name(ob) != "/d/azha/obj/mr_ring")) {
            tell_object(TP, "You can't wear things while you're shapeshifted");
            return 1;
        }
    }

    // Allow wearing by filename...
    if (!(quiet) && ob->query_property("silent_equip")) {
        quiet = 1;
    }

    if (ob->query_property("monsterweapon") && userp(TP)) {
        ob->remove();
        return 1;
    }

    if (!ob->is_armour()) {
        return notify_fail("You can't wear that, it's not armor.\n");
    }
    if (ob->query_wielded()) {
        return notify_fail("You can't wear something while wielding it.\n");
    }
    if (ob->query_worn()) {
        message("my_action", "You are already wearing that!", this_player());
        return 1;
    }

    if (!ob->wearable()) {
        message("my_action", "You cannot wear this. You do not have the required feat!", this_player());
        return 1;
    }

    if (ob->is_metal() && TP->is_class("druid")) {
        tell_object(TP, "" + ob->query_short() + " is made of metal.  You cannot wear it as it would break your druidic oath.");
        return 1;
    }

    if (TP->query_casting()) {
        message("my_action", "You are too busy casting a spell to wear that!", this_player());
        return 1;
    }

    if (!ob->mixable()) {
        message("my_action", "You must remove your other armour first!", this_player());
        return 1;
    }

    i = sizeof(limbs = ob->query_limbs());
    limbs = sort_array(limbs, "alphabetical_sort", FILTERS_D);

    while (i--) {
        if (stringp(limbs[i])) {
            continue;
        }
        if ((j = member_array(where, limbs[i])) != -1) {
            limbs[i] = limbs[i][j];
        }else {
            if (where) {
                message("my_action", "You cannot wear this on your " + where + ".", this_player());
                return 1;
            }else {
                message("my_action", "You must specify which limb you want this on.", this_player());
                return 1;
            }
        }
    }

    if (interactive(TP) && objectp(ETP) && ETP->query_property("IG_Jail") && (string)ob->query_type() != "clothing") {
        if (!quiet) {
            tell_object(TP, "You can only wear clothing while in jail.");
        }
        return 1;
    }

    level = TP->query_highest_level();
    if (ob->query_property("enchantment")) {
        if (userp(TP) && (level / 5 < ob->query_property("enchantment"))) {
            message("my_action", "You are not experienced enough to utilize this equipment", TP);
            return 1;
        }
    }

    if (!ultimate && (ob->query_property("enchantment") >= 0)) {
        if ((string*)TP->query_attackers() != ({}) && limbs[0] == "torso") {
            message("my_action", "You are too busy to put that on now!", TP);
            return 1;
        }
    }
    ob->set_hidden(0);
    if (ret = (string)this_player()->equip_armour_to_limb(ob, limbs)) {
        if (ret == "NO") {
            return 1;
        }
        if (!quiet) {
            message("my_action", ret, this_player());
        }
        return 1;
    }

    if (!quiet) {
        if (stringp(wear = ob->query_wear()) && !ob->query_property("fwear")) {
            message("my_action", wear, this_player());
        }else {
            message("my_action", "You wear " + ob->query_short() + ".", this_player());
        }
    }  

    if (itembonuses = ob->query_item_bonuses()) {
        ob->run_item_bonuses("equip", TP, itembonuses);
    }

    if (!quiet && objectp(ETP)) {
        message("other_action", (string)this_player()->query_cap_name() + " wears " + ob->query_short() + ".", environment(this_player()), ({ this_player() }));
    }

    if (interactive(TP)) {
        TP->set_property("wear_order", 1);
        ob->remove_property("wear_order");
        ob->set_property("wear_order", "" + (int)TP->query_property("wear_order") + "##" + TP->query_true_name() + "##" + what);
    }

    POISON_D->is_object_poisoned(ob, TP, "wear", 1);
    ob->set_worn(TP);
    ob->set_actualLimbs(limbs);
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

wear - put something on

%^CYAN%^SYNOPSIS%^RESET%^

wear %^ORANGE%^%^ULINE%^ITEM%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will attempt to equip the given item_name.

%^CYAN%^SEE ALSO%^RESET%^

wearall, remove, wield, unwield, limbs, inv, eq, look

");
}
