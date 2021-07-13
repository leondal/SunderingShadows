#include <std.h>
#include "../defs.h"
inherit INC + "pathnwe";

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
