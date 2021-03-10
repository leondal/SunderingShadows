#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n010_n010",
"north": RPATH "m_n010_n008",

    ]));
}

