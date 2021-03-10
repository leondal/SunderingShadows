#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_exits(([
       "north" : FTUN_ROOMS"firetemple9",
       "south" : FTUN_ROOMS"firetemple3",
       "west" : FTUN_ROOMS"firetunnelw1",
       "east" : FTUN_ROOMS"firetemple5",
       "northeast" : FTUN_ROOMS"firetemple8",
       "southeast" : FTUN_ROOMS"firetemple2",
    ] ));
}
