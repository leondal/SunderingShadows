#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p001_n007",
"southwest": RPATH "m_n001_n009",
"southeast": RPATH "m_p001_n009",
"west": RPATH "m_n001_n008",
"northwest": RPATH "m_n001_n007",
"east": RPATH "m_p001_n008",

    ]));
}

