#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_n004_p003",
"northeast": RPATH "f_n003_p003",
"east": RPATH "f_n003_p002",
"west": RPATH "f_n005_p002",

    ]));
}

