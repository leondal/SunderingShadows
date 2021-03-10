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
        "east" : mydest + "3",
        "west" : mydest + "1",
        "southeast" : mydest + "6",
        "south" : mydest + "5",
        "southwest" : mydest + "4"
    ]));
  
}
