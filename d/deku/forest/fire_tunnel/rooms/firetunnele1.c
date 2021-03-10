#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues east here and opens into a massive chamber to the "+
	"west.%^RESET%^");
    set_exits(([
       "west" : FTUN_ROOMS"firetemple4",
	 "east" : FTUN_ROOMS"firetunnele2",
    ] ));
}
