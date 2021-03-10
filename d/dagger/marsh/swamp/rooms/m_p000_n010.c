#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p000_n011",
"northeast": RPATH "m_p001_n009",
"northwest": RPATH "m_n001_n009",

    ]));
}

