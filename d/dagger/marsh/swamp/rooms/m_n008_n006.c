#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n008_n007",
"north": RPATH "m_n008_n005",
"southwest": RPATH "m_n009_n007",
"northeast": RPATH "m_n007_n005",

    ]));
}

