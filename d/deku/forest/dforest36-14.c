#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues southeast into "+
    "the forest.  A massive tower rests in the woods northeast of here.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"35-14",
       "north" : F_ROOMS"36-15",
       "northwest" : F_ROOMS"37-15",
       "southeast" : F_ROOMS"35-13",
       "northeast" : F_ROOMS"35-15",       
    ] ));
}
