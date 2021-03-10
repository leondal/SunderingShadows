#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTUNNEL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The passageway "+
    "continues northward and southward here.%^RESET%^");
    set_exits(([
       "south" : F_ROOMS"37-17",
       "north" : F_ROOMS"37-19",
    ] ));
    
}
