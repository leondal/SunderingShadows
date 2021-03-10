#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n003_n011",
"north": RPATH "m_n002_n010",
"east": RPATH "m_n001_n011",

    ]));
}

