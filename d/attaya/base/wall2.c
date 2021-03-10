#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();

    set_exits( ([
    "west" : "/d/attaya/base/wall1",
    "east" : "/d/attaya/base/wall3",
        ]) );
}
