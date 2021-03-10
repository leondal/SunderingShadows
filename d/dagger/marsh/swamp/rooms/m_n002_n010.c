#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_n003_n009",
"south": RPATH "m_n002_n011",

    ]));
}

