#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p000_n010",
"south": RPATH "m_p001_n010",
"northeast": RPATH "m_p002_n008",
"northwest": RPATH "m_p000_n008",
"east": RPATH "m_p002_n009",

    ]));
}

