#include <std.h>
inherit "/d/attaya/base/wall14";


void create() {
    ::create();

    set_exits( ([
    "southwest" : "/d/attaya/base/wall17",
    "northeast" : "/d/attaya/base/wall15",
    "up" : "/d/attaya/base/wall25",
        ]) );

}
