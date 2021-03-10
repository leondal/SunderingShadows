#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_n003_n004",
"south": RPATH "m_n002_n006",
"northeast": RPATH "m_n001_n004",

    ]));
}

