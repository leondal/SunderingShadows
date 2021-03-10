#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    string mydest;
    which_rune = 4;
    ::create();
    mydest = ELDUNES + which_rune+"_";
    set_exits(([
        "north" : mydest+"1",
        "northeast" : mydest+"2",
        //"northwest" : ELDUNES + "1_1",
        "east" : mydest+"5",
        //"west" : ELDUNES + "1_2",
        "southeast" : mydest+"8",
        "south" : mydest+"7",
        //"southwest" : ELDUNES + "1_5"
    ]));
}
