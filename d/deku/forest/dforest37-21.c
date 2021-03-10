#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTUNNEL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The passageway "+
    "continues northward and southward here.  A large %^BOLD%^"+
    "%^WHITE%^gray stone%^BOLD%^%^BLACK%^ structure rises up and "+
    "dominates your view to the north.%^RESET%^");

    add_items(({"structure","stone structure","gray stone structure"}), 
    "%^BOLD%^%^WHITE%^This massive gray stone structure rises "+
    "up to the north and dominates your view.  It stands at least "+
    "several stories high and each brick of it offers a forboding "+
    "doom to anyone beholding it.%^RESET%^");
    set_exits(([
       "south" : F_ROOMS"37-20",
       "north" : F_ROOMS"37-22",
     ] ));
    
}
