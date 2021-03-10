#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n008_n007",
"northeast": RPATH "m_n008_n006",
"southwest": RPATH "m_n010_n008",
"southeast": RPATH "m_n008_n008",

    ]));
}

