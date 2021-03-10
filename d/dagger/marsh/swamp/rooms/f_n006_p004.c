#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n005_p005",
"west": RPATH "f_n007_p004",
"east": RPATH "f_n005_p004",

    ]));
}

