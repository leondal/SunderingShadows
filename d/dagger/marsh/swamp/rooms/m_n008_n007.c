#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n008_n006",
"southeast": RPATH "m_n007_n008",
"west": RPATH "m_n009_n007",
"east": RPATH "m_n007_n007",
"south": RPATH "m_n008_n008",

    ]));
}

