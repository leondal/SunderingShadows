#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p004_n007",
"southeast": RPATH "m_p006_n007",
"east": RPATH "m_p006_n006",
"north": RPATH "m_p005_n005",
"northwest": RPATH "m_p004_n005",

    ]));
}

