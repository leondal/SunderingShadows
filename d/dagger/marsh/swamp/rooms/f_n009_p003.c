#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n008_p004",
"east": RPATH "f_n008_p003",
"west": RPATH "f_n010_p003",

    ]));
}

