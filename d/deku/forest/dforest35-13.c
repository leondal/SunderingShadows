#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues southeast into "+
    "the forest where it begins turning to the east.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"34-13",
       "north" : F_ROOMS"35-14",
       "northwest" : F_ROOMS"36-14",
       "southeast" : F_ROOMS"34-12",
       "northeast" : F_ROOMS"34-14",       
    ] ));
}
