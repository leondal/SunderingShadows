#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GY_ROAD;

void create() {
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The road "+
    "continues to the east or turns slightly before heading northwest.%^RESET%^");
    
    set_exits(([ "northwest" : "/d/deku/open/road4",
    "east" : "/d/deku/open/road2",
    ]));  
}

