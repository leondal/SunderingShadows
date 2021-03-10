#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "northwest and west here.%^RESET%^");
    set_exits(([
        "west" : FTUN_ROOMS"firetunnels22",
        "northwest" : FTUN_ROOMS"firetunnels20",
    ] ));
}