#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The forest "+
    "pathway to the south of here is blocked by the thick "+
    "debris and dead undergrowth that cover the %^GREEN%^ground"+
    "%^BOLD%^%^BLACK%^.%^RESET%^");
}
