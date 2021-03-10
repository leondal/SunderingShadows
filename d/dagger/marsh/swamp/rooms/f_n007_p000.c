#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n006_p001",
"east": RPATH "f_n006_p000",
"west": RPATH "f_n008_p000",
"north": RPATH "f_n007_p001",

    ]));
}

