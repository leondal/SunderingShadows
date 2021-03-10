#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p008_n002",
"south": RPATH "m_p007_n003",
"northwest": RPATH "m_p006_n001",

    ]));
}

