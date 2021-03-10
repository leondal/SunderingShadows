#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n003_p006",
"east": RPATH "f_n003_p005",
"west": RPATH "f_n005_p005",

    ]));
}

