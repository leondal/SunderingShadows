#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "northwest and southwest here.%^RESET%^");
    set_exits(([
        "northwest" : FTUN_ROOMS"firetunnels16",
        "southwest" : FTUN_ROOMS"firetunnels18",
    ] ));
}