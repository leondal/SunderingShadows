#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues east into "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"35-11",
       "east" : F_ROOMS"33-11",
       "south" : F_ROOMS"34-10",
       "southeast" : F_ROOMS"33-10",
       "southwest" : F_ROOMS"35-10",
       "northwest" : F_ROOMS"35-12",
    ] ));
}
