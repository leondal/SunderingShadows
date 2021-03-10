#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    string mydest;
    which_rune = 3;
    ::create();
    mydest = ELDUNES + which_rune+"_";
    set_exits(([
        //"north" : ELDUNES + "1_2",
        //"northeast" : ELDUNES + "1_3",
        //"northwest" : ELDUNES + "1_1",
        "east" : mydest+"2",
        //"west" : ELDUNES + "1_4",
        "southeast" : mydest+"5",
        "south" : mydest+"4",
        //"southwest" : ELDUNES + "1_7"
    ]));
}
