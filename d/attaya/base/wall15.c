#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();

    set_exits( ([
    "southwest" : "/d/attaya/base/wall16",
    "east" : "/d/attaya/base/wall14",
        ]) );
}
