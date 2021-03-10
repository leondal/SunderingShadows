#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n003_n011",
"southwest": RPATH "m_n005_n012",
"northwest": RPATH "m_n005_n010",
"southeast": RPATH "m_n003_n012",

    ]));
}

