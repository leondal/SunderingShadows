#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p008_n003",
"north": RPATH "m_p007_n003",
"northwest": RPATH "m_p006_n003",
"west": RPATH "m_p006_n004",
"east": RPATH "m_p008_n004",

    ]));
}

