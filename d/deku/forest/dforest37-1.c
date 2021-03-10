#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
		   set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The forest "+
    "pathway to the west and south of here is blocked by the thick "+
    "debris and dead undergrowth that cover the %^GREEN%^ground"+
    "%^BOLD%^%^BLACK%^.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"36-1",
       "north" : F_ROOMS"37-2",
       "northeast" : F_ROOMS"36-2",
    ] ));
}
