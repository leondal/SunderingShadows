#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long() +"  %^BOLD%^%^BLACK%^The forest "+
    "pathway to the north and west of here is blocked by "+
    "thick undergrowth that grows up in those direction.  "+
    "A pathway to the northeast allows travel only in that "+
    "direction.%^RESET%^");
    set_exits(([
       "northeast" : P_ROOMS"fplains01",
       "west" : F_ROOMS"33-16",
       "south" : F_ROOMS"32-15",
       "southwest" : F_ROOMS"33-15",
       
    ] ));
}
