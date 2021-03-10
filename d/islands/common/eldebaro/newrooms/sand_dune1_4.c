#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    which_rune = 1;
    ::create();

    set_exits(([
        "north" : ELDUNES + "1_1",
        "northeast" : ELDUNES + "1_2",
        //"northwest" : ELDUNES + "1_1",
        "east" : ELDUNES + "1_5",
        //"west" : ELDUNES + "1_2",
        "southeast" : ELDUNES + "1_8",
        "south" : ELDUNES + "1_7",
        //"southwest" : ELDUNES + "1_5"
    ]));
}
