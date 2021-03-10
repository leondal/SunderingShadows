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
        "north" : mydest+"4",
        "northeast" : mydest+"5",
        //"northwest" : ELDUNES + "1_2",
        "east" : mydest+"8",
        //"west" : ELDUNES + "1_5",
        //"southeast" : ELDUNES + "1_8",
        //"south" : ELDUNES + "1_9",
        //"southwest" : ELDUNES + "1_8"
    ]));
}
