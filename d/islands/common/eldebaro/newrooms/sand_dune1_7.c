#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    which_rune = 1;
    ::create();

    set_exits(([
        "north" : ELDUNES + "1_4",
        "northeast" : ELDUNES + "1_5",
        //"northwest" : ELDUNES + "1_2",
        "east" : ELDUNES + "1_8",
        //"west" : ELDUNES + "1_5",
        //"southeast" : ELDUNES + "1_8",
        //"south" : ELDUNES + "1_9",
        //"southwest" : ELDUNES + "1_8"
    ]));
}
