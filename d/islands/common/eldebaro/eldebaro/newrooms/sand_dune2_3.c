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
        //"north" : ELDUNES + "1_2",
        //"northeast" : ELDUNES + "1_3",
        //"northwest" : ELDUNES + "1_1",
        //"east" : ELDUNES + "1_3",
        "west" : mydest+"2",
        //"southeast" : ELDUNES + "1_6",
        "south" : mydest+"6",
        "southwest" : mydest+"5"
    ]));
}
