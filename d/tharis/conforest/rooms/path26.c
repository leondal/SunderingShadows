#include <std.h>
#include "../defs.h"
inherit INC + "pathwe";

void create()
{
    ::create();
    set_exits(
        ([
            "northwest" : ROOMS + "path25",
            "east" : ROOMS + "path27",
            "grove" : "/d/magic/temples/nimnavanon/nimnavanon",
         ]));
}
