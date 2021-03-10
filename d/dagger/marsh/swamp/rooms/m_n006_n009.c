#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_n005_n010",
"northeast": RPATH "m_n005_n008",
"north": RPATH "m_n006_n008",
"southwest": RPATH "m_n007_n010",

    ]));
}

