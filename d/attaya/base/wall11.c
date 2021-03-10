
#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "northwest" : "/d/attaya/base/wall12",
    "southeast" : "/d/attaya/base/wall10",
        ]) );
}
