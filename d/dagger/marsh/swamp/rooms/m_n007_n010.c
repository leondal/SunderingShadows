#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_n006_n011",
"north": RPATH "m_n007_n009",
"southwest": RPATH "m_n008_n011",
"northeast": RPATH "m_n006_n009",

    ]));
}

