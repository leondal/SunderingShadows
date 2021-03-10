#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n001_n007",
"southeast": RPATH "m_n001_n009",
"west": RPATH "m_n003_n008",
"east": RPATH "m_n001_n008",

    ]));
}

