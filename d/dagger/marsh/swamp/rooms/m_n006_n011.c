#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n006_n012",
"east": RPATH "m_n005_n011",
"southeast": RPATH "m_n005_n012",
"northwest": RPATH "m_n007_n010",
"northeast": RPATH "m_n005_n010",

    ]));
}

