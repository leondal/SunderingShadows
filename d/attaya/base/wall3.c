#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();

    set_exits( ([
    "west" : "/d/attaya/base/wall2",
    "northeast" : "/d/attaya/base/wall4",
        ]) );
}
