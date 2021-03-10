#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p007_n004",
"southwest": RPATH "m_p005_n005",
"north": RPATH "m_p006_n003",

    ]));
}

