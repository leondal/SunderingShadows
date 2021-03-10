#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n002_n011",
"west": RPATH "m_n004_n011",
"south": RPATH "m_n003_n012",

    ]));
}

