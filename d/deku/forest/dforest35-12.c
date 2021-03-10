#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues southeast into "+
    "the forest where it begins turning to the east.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"36-12",
       "south" : F_ROOMS"35-11",
       "northwest" : F_ROOMS"36-13",
       "southeast" : F_ROOMS"34-11",
       "southwest" : F_ROOMS"36-11",       
    ] ));
}
