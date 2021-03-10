#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p007_n009",
"west": RPATH "m_p006_n010",
"south": RPATH "m_p007_n011",

    ]));
}

