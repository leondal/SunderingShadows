#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("Two massive stone pillars here mark the edges of a front gate to "
        "a fortress that stood here hundreds of years ago.  Large stone bricks "
        "shelter you from the blowing sands as you pass.\n"+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room25",
        "south" : ROOMS"room27",
        "west" : ROOMS"room23",
        "east" : ROOMS"room32",
    ]));

    set_items(([
        "pillars" : "They are large columns of stone with rusty metal hinges attached to them.",
        "bricks" : "They are carved of sandstone and are about ten feet high each!"
    ]));
}