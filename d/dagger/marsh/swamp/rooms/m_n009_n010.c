#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n010_n010",
"northeast": RPATH "m_n008_n009",
"southeast": RPATH "m_n008_n011",
"east": RPATH "m_n008_n010",

    ]));
}

