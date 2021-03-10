#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  A wall of fire to the "+
    "east and south blocks passage in those directions."+
    "%^RESET%^");
    set_exits(([
       "north" : FTUN_ROOMS"firetemple4",
       "west" : FTUN_ROOMS"firetemple2",
       "northwest" : FTUN_ROOMS"firetemple5",
    ] ));
}
