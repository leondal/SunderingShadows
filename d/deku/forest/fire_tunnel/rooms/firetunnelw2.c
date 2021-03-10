#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
     set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues north, south, east, and west here.%^RESET%^");
    set_exits(([
	 "west" : FTUN_ROOMS"firetunnelw3",
	 "east" : FTUN_ROOMS"firetunnelw1",
       "north" : FTUN_ROOMS"firetunnelwn1",
       "south" : FTUN_ROOMS"firetunnelws1"
    ] ));
}
