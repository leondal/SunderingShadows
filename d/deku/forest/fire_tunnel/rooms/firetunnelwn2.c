#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel dead ends "+
    "here and your only option to trek back to the south.%^RESET%^");
    set_exits(([
        "south" : FTUN_ROOMS"firetunnelw4",
    ] ));
}

