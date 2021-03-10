#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel dead ends "+
    "here and your only option to trek back to the east.%^RESET%^");
    set_exits(([
        "east" : FTUN_ROOMS"firetunnels2",
    ] ));
}

