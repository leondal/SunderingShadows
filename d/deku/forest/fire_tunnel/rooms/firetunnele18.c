#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "southwest and east here.%^RESET%^");
    set_exits(([
        "east" : FTUN_ROOMS"firetunnele19",
        "southwest" : FTUN_ROOMS"firetunnele17",
    ] ));
}