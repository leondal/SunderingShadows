#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The large "+
    "south wall of verbobone rises up to the north, blocking "+
    "the forest path in that direction.%^RESET%^");
}
