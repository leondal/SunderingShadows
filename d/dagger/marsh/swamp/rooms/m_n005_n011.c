#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n005_n012",
"west": RPATH "m_n006_n011",

    ]));
}

