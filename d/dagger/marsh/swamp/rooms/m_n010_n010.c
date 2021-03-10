#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_n009_n011",
"southwest": RPATH "m_n011_n011",
"north": RPATH "m_n010_n009",
"east": RPATH "m_n009_n010",

    ]));
}

