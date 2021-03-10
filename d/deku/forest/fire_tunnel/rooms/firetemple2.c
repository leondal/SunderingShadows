#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_exits(([
       "north" : FTUN_ROOMS"firetemple5",
       "west" : FTUN_ROOMS"firetemple3",
       "northwest" : FTUN_ROOMS"firetemple6",
       "east" : FTUN_ROOMS"firetemple1",
       "northeast" : FTUN_ROOMS"firetemple4",
	 "south" : FTUN_ROOMS"firetunnels1"
    ] ));
}
