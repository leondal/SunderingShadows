#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n002_n008",
"south": RPATH "m_n001_n009",
"east": RPATH "m_p000_n008",
"north": RPATH "m_n001_n007",

    ]));
}

