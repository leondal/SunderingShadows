#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "northeast and southwest here.%^RESET%^");
    set_exits(([
        "northeast" : FTUN_ROOMS"firetunnelw17",
        "southwest" : FTUN_ROOMS"firetunnelw19",
    ] ));
}