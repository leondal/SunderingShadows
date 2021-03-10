#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "southeast" : "/d/attaya/base/wall9",
    "northwest" : "/d/attaya/base/wall11",
    "up" : "/d/attaya/base/wall26",
        ]) );
}
