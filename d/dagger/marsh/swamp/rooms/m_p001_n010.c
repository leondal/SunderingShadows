#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p000_n011",
"northeast": RPATH "m_p002_n009",
"north": RPATH "m_p001_n009",

    ]));
}

