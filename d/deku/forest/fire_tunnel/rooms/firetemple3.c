#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  A wall of fire to the "+
    "west and south blocks passage in those directions."+
    "%^RESET%^");
    set_exits(([
       "north" : FTUN_ROOMS"firetemple6",
       //"west" : FTUN_ROOMS"firetemple3",
       //"northwest" : FTUN_ROOMS"firetemple6",
       "east" : FTUN_ROOMS"firetemple2",
       "northeast" : FTUN_ROOMS"firetemple5",
    ] ));
}

