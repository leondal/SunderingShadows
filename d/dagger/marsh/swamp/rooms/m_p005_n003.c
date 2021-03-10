#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p005_n002",
"southwest": RPATH "m_p004_n004",
"east": RPATH "m_p006_n003",

    ]));
}

