#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n006_n012",
"north": RPATH "m_n005_n011",
"northwest": RPATH "m_n006_n011",
"northeast": RPATH "m_n004_n011",
"south": RPATH "m_n005_n013",

    ]));
}

