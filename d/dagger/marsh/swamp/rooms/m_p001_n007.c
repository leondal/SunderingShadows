#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p002_n006",
"west": RPATH "m_p000_n007",
"northwest": RPATH "m_p000_n006",
"southeast": RPATH "m_p002_n008",
"southwest": RPATH "m_p000_n008",

    ]));
}

