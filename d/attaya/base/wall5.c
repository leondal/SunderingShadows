#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "southwest" : "/d/attaya/base/wall4",
    "northeast" : "/d/attaya/base/wall6",
        ]) );
}
