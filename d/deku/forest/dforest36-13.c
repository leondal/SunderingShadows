#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues southeast into "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"37-13",
       "south" : F_ROOMS"36-12",
       "northwest" : F_ROOMS"37-14",
       "southwest" : F_ROOMS"37-12",
       "southeast" : F_ROOMS"35-12",
    ] ));
}
