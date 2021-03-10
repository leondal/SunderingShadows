#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GY_ROAD;

void create() {
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The road "+
    "continues to the east or the west here.%^RESET%^");
    
    set_exits(([ "west" : "/d/deku/open/road3",
    "east" : "/d/deku/open/road1",
    ]));  
}
