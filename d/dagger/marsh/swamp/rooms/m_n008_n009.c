#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n007_n009",
"southwest": RPATH "m_n009_n010",

    ]));
}

