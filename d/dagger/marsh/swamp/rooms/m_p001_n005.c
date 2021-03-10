#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p002_n006",
"northwest": RPATH "m_p000_n004",
"northeast": RPATH "m_p002_n004",
"southwest": RPATH "m_p000_n006",
"west": RPATH "m_p000_n005",

    ]));
}

