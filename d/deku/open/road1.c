#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GY_ROAD;

void create() {
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The road "+
    "continues toward the west here or enters the forest directly "+
    "to the east.%^RESET%^");
    set_exits(([ "west" : "/d/deku/open/road2",
    "east" : "/d/deku/forest/dforest37-19",
    ]));  
}
