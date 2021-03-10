#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n001_n012",
"west": RPATH "m_n002_n011",
"east": RPATH "m_p000_n011",

    ]));
}

