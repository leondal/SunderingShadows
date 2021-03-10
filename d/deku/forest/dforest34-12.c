#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues east into "+
    "the forest.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"33-12",
       "north" : F_ROOMS"34-13",
       "northwest" : F_ROOMS"35-13",
       "northeast" : F_ROOMS"33-13",       
    ] ));
}
