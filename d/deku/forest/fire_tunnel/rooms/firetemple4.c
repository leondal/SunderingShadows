#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_exits(([
       "north" : FTUN_ROOMS"firetemple7",
       "west" : FTUN_ROOMS"firetemple5",
       "northwest" : FTUN_ROOMS"firetemple8",
       "south" : FTUN_ROOMS"firetemple1",
       "southwest" : FTUN_ROOMS"firetemple2",
	 "east" : FTUN_ROOMS"firetunnele1",
    ] ));
}
