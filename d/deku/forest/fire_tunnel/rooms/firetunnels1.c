#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues south here and opens into a massive chamber to the "+
	"north.%^RESET%^");
    set_exits(([
       "north" : FTUN_ROOMS"firetemple2",
	 "south" : FTUN_ROOMS"firetunnels2",
    ] ));
}
