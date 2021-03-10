#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n008_n005",
"east": RPATH "m_n006_n004",
"northeast": RPATH "m_n006_n003",
"south": RPATH "m_n007_n005",

    ]));
}

