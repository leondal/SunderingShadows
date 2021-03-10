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
        "north" : mydest+"5",
        "northeast" : mydest+"6",
        "northwest" : mydest+"4",
        "east" : mydest+"9",
        "west" : mydest+"7",
        //"southeast" : ELDUNES + "1_8",
        //"south" : ELDUNES + "1_9",
        //"southwest" : ELDUNES + "1_8"
    ]));
}
