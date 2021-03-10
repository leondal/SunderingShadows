#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p007_n004",
"northeast": RPATH "m_p008_n002",
"north": RPATH "m_p007_n002",
"west": RPATH "m_p006_n003",

    ]));
}

