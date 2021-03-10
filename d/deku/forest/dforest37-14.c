#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues southeast into "+
    "the forest.  Travel is made impossible by the thick "+
    "undergrowth that covers the ground near the river to the "+
    "northwest.%^RESET%^");
    set_exits(([       
       "south" : F_ROOMS"37-13",
       "southeast" : F_ROOMS"36-13",
       ] ));
}
