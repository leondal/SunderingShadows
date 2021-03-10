#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p001_n010",
"east": RPATH "m_p003_n009",
"west": RPATH "m_p001_n009",

    ]));
}

