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
        "north" : mydest+"6",
        //"northeast" : ELDUNES + "1_6",
        "northwest" : mydest+"5",
        //"east" : ELDUNES + "1_9",
        "west" : mydest+"8",
        //"southeast" : ELDUNES + "1_8",
        //"south" : ELDUNES + "1_9",
        //"southwest" : ELDUNES + "1_8"
    ]));
}
