#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n008_n007",
"northeast": RPATH "m_n006_n006",
"south": RPATH "m_n007_n008",

    ]));
}

