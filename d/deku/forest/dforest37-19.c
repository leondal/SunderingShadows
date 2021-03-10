#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTUNNEL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The passageway "+
    "continues northward and southward here.  A dirt road "+
    "comes into view directly to the west.%^RESET%^");
    set_exits(([
       "south" : F_ROOMS"37-18",
       "north" : F_ROOMS"37-20",
       "west" : "/d/deku/open/road1",
    ] ));
    
}
