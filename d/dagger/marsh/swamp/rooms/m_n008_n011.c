#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n009_n011",
"northwest": RPATH "m_n009_n010",
"northeast": RPATH "m_n007_n010",

    ]));
}

