#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_n002_n010",
"north": RPATH "m_n003_n008",

    ]));
}

