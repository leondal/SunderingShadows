#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("A tall sandstone wall stands almost completely intact here!  It towers "
        "above you, a reminder to the power this fortress once held.\n"
        ""+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room31",
        "south" : ROOMS"room33",
        "west" : ROOMS"room26",
        "east" : ROOMS"room37",
    ]));
    
    set_items(([
        "wall" : "It is about 4 stories tall and made of sandstone blocks."
    ]));
}