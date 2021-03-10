#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n004_n007",
"north": RPATH "m_n005_n006",
"south": RPATH "m_n005_n008",

    ]));
}

