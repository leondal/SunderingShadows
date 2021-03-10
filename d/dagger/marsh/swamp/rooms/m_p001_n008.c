#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p002_n008",
"west": RPATH "m_p000_n008",

    ]));
}

