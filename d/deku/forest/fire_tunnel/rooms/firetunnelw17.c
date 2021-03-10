#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "east and southwest here.%^RESET%^");
    set_exits(([
        "east" : FTUN_ROOMS"firetunnelw16",
        "southwest" : FTUN_ROOMS"firetunnelw18",
    ] ));
}