#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The forest "+
    "pathway to the south of here is blocked by the thick "+
    "debris and dead undergrowth that cover the %^GREEN%^ground"+
    "%^BOLD%^%^BLACK%^.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"3-1",
       "north" : F_ROOMS"2-2",
       "northwest" : F_ROOMS"3-2",
    ] ));
}
