#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_n004_n007",
"east": RPATH "m_n002_n008",
"south": RPATH "m_n003_n009",

    ]));
}

