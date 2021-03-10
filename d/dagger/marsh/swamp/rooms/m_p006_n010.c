#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p007_n009",
"east": RPATH "m_p007_n010",
"southwest": RPATH "m_p005_n011",

    ]));
}

