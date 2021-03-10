#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_exits(([
       "south" : FTUN_ROOMS"firetemple5",
       "west" : FTUN_ROOMS"firetemple9",
       "east" : FTUN_ROOMS"firetemple7",
       "southeast" : FTUN_ROOMS"firetemple4",
       "southwest" : FTUN_ROOMS"firetemple6",
	 "north" : FTUN_ROOMS"firetunneln1"
    ] ));
}
