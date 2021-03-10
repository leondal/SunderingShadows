#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n002_n008",
"southeast": RPATH "m_p000_n008",
"northwest": RPATH "m_n002_n006",
"south": RPATH "m_n001_n008",
"east": RPATH "m_p000_n007",

    ]));
}

