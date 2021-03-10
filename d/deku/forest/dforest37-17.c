#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTUNNEL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The passageway "+
    "continues northward and breaks into the open forest directly "+
    "to the south of here.%^RESET%^");
    set_exits(([
       "south" : F_ROOMS"37-16",
       "north" : F_ROOMS"37-18",
    ] ));
    
}
