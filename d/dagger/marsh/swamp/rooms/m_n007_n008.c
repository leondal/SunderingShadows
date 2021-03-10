#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_n008_n007",
"north": RPATH "m_n007_n007",
"south": RPATH "m_n007_n009",
"east": RPATH "m_n006_n008",

    ]));
}

