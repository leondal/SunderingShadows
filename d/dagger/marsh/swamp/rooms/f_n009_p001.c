#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n008_p001",
"west": RPATH "f_n010_p001",
"southeast": RPATH "f_n008_p000",

    ]));
}

