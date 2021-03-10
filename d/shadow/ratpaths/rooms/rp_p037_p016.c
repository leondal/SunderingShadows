#include <std.h>
#include <daemons.h>
#include "../common.h"

inherit DEEPROAD;

void create()
{
    ::create();
    set_long(query_long() + " Path to the east is blocked with massive metal %^WHITE%^gates%^CYAN%^.
");
    set_exits(([
                   "west" : PATH + "rp_p036_p016",

                   ]));
    add_item("gates", "These are massive metal gates with dwarven runes edged into the surface.");
    add_item("runes", "Edged into the surface dwarven runes one might try to read.");
}

void init()
{
    ::init();
    add_action("read", "read");
}

int read(string str)
{
    if (str != "gates" && str != "runes") {
        return 0;
    }
    message("reading", LANGUAGE_D->translate("Targ Kinaro", "dwarvish", TP, 1), TP);
    return 1;
}
