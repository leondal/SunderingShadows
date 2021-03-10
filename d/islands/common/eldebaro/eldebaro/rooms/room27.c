#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("You climb up onto a large flat slab of stone.  It was a floor to "
        "the fortress at one time and has tilted and raised from the ground since.  "
        "A large symbol is carved into the slab but most of the smaller markings "
        "have eroded away.\n"+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room26",
        "south" : ROOMS"room28",
        "west" : "/d/shadow/virtual/sea/eldebaro.dock",
        "east" : ROOMS"room33",
    ]));

    set_items(([
        "symbol" : "It is the feared marking of the Kinnesaruda Legacy.",
        "slab" : "A large flat slab of stone that extends to a height of twenty feet above the sand at the corner."
    ]));
}