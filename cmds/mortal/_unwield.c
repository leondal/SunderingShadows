#include <std.h>
inherit DAEMON;

int cmd_unwield(string str)
{
    object ob, myplayer;
    string unwieldf;
    function f;

    if (!str) {
        return notify_fail("Unwield what?\n");
    }

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!ob = present(str, TP)) {
        return notify_fail("You don't have that!\n");
    }

    if (!ob->query_wielded()) {
        return notify_fail("You are not wielding that!\n");
    }
    if (ob->query_property("enchantment") && (int)ob->query_property("enchantment") < 0) {
        write("The curse on this item prevents you from unwielding it.");
        return 1;
    }
    ob->__ActuallyUnwield();
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

unwield - remove something from your hand

%^CYAN%^SYNOPSIS%^RESET%^

unwield %^ORANGE%^%^ULINE%^ITEM%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will put a weld ITEM into your immediate inventory.

%^CYAN%^SEE ALSO%^RESET%^

wield, remove, inv, limbs, eq
");
}
