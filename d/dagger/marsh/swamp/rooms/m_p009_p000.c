#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p010_p000",
"northeast": RPATH "m_p010_p001",
"southwest": RPATH "m_p008_n001",
"south": RPATH "m_p009_n001",
"west": RPATH "m_p008_p000",

    ]));
}

