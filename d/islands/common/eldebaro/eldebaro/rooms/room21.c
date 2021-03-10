#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long(""+::query_long()+"There are three squarish boulders here, lying in a heap.\n");

    set_exits(([
        "north" : ROOMS"room20",
        "west" : ROOMS"room16",
        "east" : "/d/shadow/virtual/sea/eldebaro.dock",
    ]));

    set_items((["boulders" : "These massive rocks lay together in a disorganized "
                             "jumble, partly covered with sand."
    ]));
}