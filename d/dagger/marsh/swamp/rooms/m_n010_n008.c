#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n009_n007",
"south": RPATH "m_n010_n009",

    ]));
}

