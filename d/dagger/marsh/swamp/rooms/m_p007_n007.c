#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p008_n008",
"northwest": RPATH "m_p006_n006",
"south": RPATH "m_p007_n008",
"east": RPATH "m_p008_n007",
"west": RPATH "m_p006_n007",

    ]));
}

