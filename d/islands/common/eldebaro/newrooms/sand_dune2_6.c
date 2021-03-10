#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    string mydest;
    which_rune = 2;
    ::create();
    mydest = ELDUNES + which_rune+"_";
    set_exits(([
        "north" : mydest+"3",
        //"northeast" : ELDUNES + "1_2",
        "northwest" : mydest+"2",
        //"east" : ELDUNES + "1_5",
        "west" : mydest+"5",
        //"southeast" : ELDUNES + "1_8",
        "south" : mydest+"9",
        "southwest" : mydest+"8"
    ]));
}
