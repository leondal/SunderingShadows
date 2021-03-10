#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues northward here and opens into a massive chamber to the "+
	"south.%^RESET%^");
    set_exits(([
       "north" : FTUN_ROOMS"firetunneln2",
	 "south" : FTUN_ROOMS"firetemple8",
    ] ));
}
