#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p000_n001",
"east": RPATH "m_p002_n002",
"west": RPATH "m_p000_n002",
"southeast": RPATH "m_p002_n003",

    ]));
}

