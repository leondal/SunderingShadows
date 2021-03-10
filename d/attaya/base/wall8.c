#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "north" : "/d/attaya/base/wall9",
    "south" : "/d/attaya/base/wall7",
        ]) );
}
