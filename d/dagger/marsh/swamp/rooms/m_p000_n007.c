#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p001_n007",
"north": RPATH "m_p000_n006",
"west": RPATH "m_n001_n007",

    ]));
}

