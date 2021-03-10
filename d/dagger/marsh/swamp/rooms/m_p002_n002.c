#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p001_n002",
"south": RPATH "m_p002_n003",
"northeast": RPATH "m_p003_n001",

    ]));
}

