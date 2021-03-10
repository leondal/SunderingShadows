#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "northeast and south here.%^RESET%^");
    set_exits(([
        "northeast" : FTUN_ROOMS"firetunnelw18",
        "south" : FTUN_ROOMS"firetunnelw20",
    ] ));
}