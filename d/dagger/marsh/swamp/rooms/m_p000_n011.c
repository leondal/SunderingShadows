#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p000_n010",
"northeast": RPATH "m_p001_n010",
"southwest": RPATH "m_n001_n012",
"west": RPATH "m_n001_n011",

    ]));
}

