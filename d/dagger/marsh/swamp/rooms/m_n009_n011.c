#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n008_n011",
"northwest": RPATH "m_n010_n010",
"south": RPATH "m_n009_n012",
"southwest": RPATH "m_n010_n012",

    ]));
}

