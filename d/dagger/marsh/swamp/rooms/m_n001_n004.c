#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p000_n004",
"southeast": RPATH "m_p000_n005",
"southwest": RPATH "m_n002_n005",
"northwest": RPATH "m_n002_n003",

    ]));
}

