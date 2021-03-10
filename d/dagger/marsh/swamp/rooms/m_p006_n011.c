#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p007_n011",
"west": RPATH "m_p005_n011",

    ]));
}

