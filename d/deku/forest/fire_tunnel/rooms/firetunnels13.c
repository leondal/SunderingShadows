#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues north and south here.%^RESET%^");
    set_exits(([
       "north" : FTUN_ROOMS"firetunnels12",
       "south" : FTUN_ROOMS"firetunnels14"
    ] ));
}
