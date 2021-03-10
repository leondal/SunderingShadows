#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the west and continues east into "+
    "the forest where it turns to the northeast.  A "+
    "%^BOLD%^%^BLACK%^bridge%^CYAN%^ runs across the river "+
    "here to reach its south bank.%^RESET%^");
    add_items(({"bridge","old bridge","wooden bridge"}), 
    "%^BOLD%^%^BLACK%^This old bridge stretches uneasily across "+
    "the silent river here.  It has been quickly constructed "+
    "from some of the gnarled and withered limbs of the "+
    "trees nearby.  It appears to be the only means of "+
    "passing across the river however daunting it maybe.%^RESET%^");   
    set_exits(([
       "west" : F_ROOMS"34-12",
       "east" : F_ROOMS"32-12",
       "bridge" : F_ROOMS"33-11",
       "north" : F_ROOMS"33-13",
       "northwest" : F_ROOMS"34-13",
       "northeast" : F_ROOMS"32-13",       
    ] ));
}
