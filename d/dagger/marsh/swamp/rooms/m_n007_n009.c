#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_n008_n008",
"north": RPATH "m_n007_n008",
"south": RPATH "m_n007_n010",
"southwest": RPATH "m_n008_n010",
"west": RPATH "m_n008_n009",

    ]));
}

