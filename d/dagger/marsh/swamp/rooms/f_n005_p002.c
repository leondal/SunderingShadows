#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n006_p002",
"south": RPATH "f_n005_p001",
"east": RPATH "f_n004_p002",

    ]));
}

