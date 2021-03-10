#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p006_n011",
"northwest": RPATH "m_p004_n010",
"northeast": RPATH "m_p006_n010",

    ]));
}

