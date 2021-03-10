#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel dead ends "+
    "here and your only option to trek back to the north.%^RESET%^");
    set_exits(([
        "north" : FTUN_ROOMS"firetunnelw12",
    ] ));
}

