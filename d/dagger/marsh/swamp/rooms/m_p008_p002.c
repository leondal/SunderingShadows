#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p007_p002",
"south": RPATH "m_p008_p001",
"east": RPATH "m_p009_p002",

    ]));
}

