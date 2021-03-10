#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues north, south, east, and west here.%^RESET%^");
    set_exits(([
	 "east" : FTUN_ROOMS"firetunnelw13",
	 "west" : FTUN_ROOMS"firetunnelw15",
       "north" : FTUN_ROOMS"firetunnelwn7",
       "south" : FTUN_ROOMS"firetunnelws7"
    ] ));
}
