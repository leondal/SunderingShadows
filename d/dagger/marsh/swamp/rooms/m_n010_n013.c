#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n009_n013",
"west": RPATH "m_n011_n013",
"north": RPATH "m_n010_n012",

    ]));
}

