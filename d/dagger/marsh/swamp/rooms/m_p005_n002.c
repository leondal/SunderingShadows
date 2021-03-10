#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p005_n001",
"south": RPATH "m_p005_n003",
"northwest": RPATH "m_p004_n001",
"east": RPATH "m_p006_n002",
"northeast": RPATH "m_p006_n001",

    ]));
}

