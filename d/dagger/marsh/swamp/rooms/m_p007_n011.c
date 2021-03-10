#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p006_n011",
"north": RPATH "m_p007_n010",

    ]));
}

