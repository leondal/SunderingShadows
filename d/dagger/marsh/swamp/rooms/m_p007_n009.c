#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p008_n008",
"north": RPATH "m_p007_n008",
"southwest": RPATH "m_p006_n010",
"south": RPATH "m_p007_n010",

    ]));
}

