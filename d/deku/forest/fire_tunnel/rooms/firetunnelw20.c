#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "north and southwest here.%^RESET%^");
    set_exits(([
        "north" : FTUN_ROOMS"firetunnelw19",
        "southwest" : FTUN_ROOMS"firetunnelw21",
    ] ));
}