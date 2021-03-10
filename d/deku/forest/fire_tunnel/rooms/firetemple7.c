#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  A wall of fire to the "+
    "north and east blocks passage in those directions."+
    "%^RESET%^");
    set_exits(([
       "south" : FTUN_ROOMS"firetemple4",
       "west" : FTUN_ROOMS"firetemple8",
       "southwest" : FTUN_ROOMS"firetemple5",
    ] ));
}
