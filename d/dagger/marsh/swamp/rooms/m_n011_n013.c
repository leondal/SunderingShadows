#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n010_n013",
"northeast": RPATH "m_n010_n012",
"north": RPATH "m_n011_n012",

    ]));
}

