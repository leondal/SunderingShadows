#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit FPLAINS;

void create() {
    ::create();
    set_long(TO->query_long()+ "%^BOLD%^%^BLACK%^  The path "+
    "dives into the forest to the southwest of here or continues "+
    "northeast to meet the southeast corner of the %^YELLOW%^northern "+
    "plains%^BOLD%^%^BLACK%^.%^RESET%^");
    add_item(({"plains","north plains"}),"%^YELLOW%^The corner of "+
    "these plains is just northeast of here.  They cover the "+
    "majority of the northern part of the island and like the forest, "+
    "show few signs of life.%^RESET%^");
    set_exits(([
    "northeast" : P_ROOMS"plains01",
    "southwest" : P_ROOMS"fplains05",
    ]));
}
    