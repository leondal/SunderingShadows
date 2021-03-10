#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTUNNEL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The passageway "+
    "continues northward and southward here.  The entrance "+
    "to the large %^BOLD%^%^WHITE%^gray stone%^BOLD%^%^BLACK%^ "+
    "structure lies directly to the north.%^RESET%^");

    add_items(({"structure","stone structure","gray stone structure"}), 
    "%^BOLD%^%^WHITE%^The entrance to this massive gray stone "+
    "rests just north of here.  The sense of doom that surrounds "+
    "it has increase tenfold now and you begin to question your "+
    "reasoning for coming this far.%^RESET%^");
    set_exits(([
       "south" : F_ROOMS"37-21",
       "north" : "/d/deku/fortress/foyer",
     ] ));
    
}
