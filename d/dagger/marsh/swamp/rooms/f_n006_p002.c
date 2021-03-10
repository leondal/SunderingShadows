#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_n006_p001",
"east": RPATH "f_n005_p002",
"northeast": RPATH "f_n005_p003",

    ]));
}

