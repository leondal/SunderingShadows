#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p009_n002",
"north": RPATH "m_p009_p000",
"east": RPATH "m_p010_n001",
"northeast": RPATH "m_p010_p000",

    ]));
}

