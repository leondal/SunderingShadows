#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The large "+
    "west wall of verbobone rises up to the east, blocking "+
    "the forest path in that direction.%^RESET%^");
}
