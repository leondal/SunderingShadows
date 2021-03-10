#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p000_n010",
"northwest": RPATH "m_n002_n008",
"northeast": RPATH "m_p000_n008",
"north": RPATH "m_n001_n008",

    ]));
}

