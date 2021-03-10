#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n009_p001",
"north": RPATH "f_n010_p002",

    ]));
}

