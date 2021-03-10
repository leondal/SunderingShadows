#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  A wall of fire to the "+
    "west and north blocks passage in those directions.%^RESET%^");
	/* direction."+
    "  A small %^BLUE%^alcove%^RESET%^%^RED%^ is set into "+
    "the north wall.%^RESET%^");
    add_item("alcove","%^RED%^This alcove provides a small room "+
    "in the north wall here.  Its hard to tell what's "+
    "inside of it from here.%^RESET%^");*/
    set_exits(([
       "south" : FTUN_ROOMS"firetemple6",
       "east" : FTUN_ROOMS"firetemple8",
       "southeast" : FTUN_ROOMS"firetemple5",
    ] ));
}
