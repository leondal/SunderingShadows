#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel turns "+
    "west and southeast here.%^RESET%^");
    set_exits(([
        "west" : FTUN_ROOMS"firetunneln22",
        "southeast" : FTUN_ROOMS"firetunneln20",
    ] ));
}