#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues west here and opens into a massive chamber to the "+
	"east.%^RESET%^");
    set_exits(([
       "east" : FTUN_ROOMS"firetemple6",
	 "west" : FTUN_ROOMS"firetunnelw2",
    ] ));
}
