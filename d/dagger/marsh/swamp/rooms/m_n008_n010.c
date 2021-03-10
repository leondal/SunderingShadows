#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n007_n009",
"west": RPATH "m_n009_n010",

    ]));
}

