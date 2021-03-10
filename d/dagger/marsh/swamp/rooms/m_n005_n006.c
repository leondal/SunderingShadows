#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n005_n007",
"north": RPATH "m_n005_n005",
"west": RPATH "m_n006_n006",
"northeast": RPATH "m_n004_n005",

    ]));
}

