#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n005_n005",
"east": RPATH "m_n005_n006",
"southwest": RPATH "m_n007_n007",

    ]));
}

