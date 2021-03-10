#include <std.h>
inherit DAEMON;

int cmd_remove(string str)
{
    object ob;
    if (!str) {
        return notify_fail("Remove what?\n");
    }

    if (str == "all") {

        object * worn;

        worn = all_inventory(TP);

        sizeof(worn) && filter_array(worn, (:$1->query_worn():));
        sizeof(worn) && filter_array(worn, (:$1->query_property("enchantment") && $1->query_property("enchantment") > 0:));
        sizeof(worn) && worn->unwear();
        sizeof(worn) && remove_property("wear_order");

        return 1;
    }

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!(ob = present(str, TP))) {
        notify_fail("You don't have that!\n");
        return 0;
    }
    if (!ob->query_worn()) {
        message("my_action", "You are not wearing that!", this_player());
        return 1;
    }

    if (ob->query_property("enchantment") && ob->query_property("enchantment") < 0) {
        write("The curse on this item prevents you from removing it.");
        return 1;
    }
    ob->unwear(); // item bonuses are here - on armour/pocketarmour inherits. N, 7/12.
    ob->remove_property("wear_order");
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

remove - undress *blush*

%^CYAN%^SYNOPSIS%^RESET%^

remove %^ORANGE%^%^ULINE%^ITEM%^RESET%^|all

%^CYAN%^DESCRIPTION%^RESET%^

This command will remove ITEM from whatever limb it is currently being worn on.

With argument all you'll remove all worn items.

%^CYAN%^SEE ALSO%^RESET%^

wear, wield, unwield, inv, limbs, eq
");
}
