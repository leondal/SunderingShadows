#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n008_n002",
"south": RPATH "f_n009_n003",
"west": RPATH "f_n010_n002",
"southwest": RPATH "f_n010_n003",

    ]));
}

