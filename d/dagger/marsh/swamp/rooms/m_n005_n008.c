#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n005_n007",
"southwest": RPATH "m_n006_n009",
"west": RPATH "m_n006_n008",

    ]));
}

