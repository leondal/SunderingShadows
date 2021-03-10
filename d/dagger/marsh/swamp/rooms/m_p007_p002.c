#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p006_p002",
"north": RPATH "m_p007_p003",
"east": RPATH "m_p008_p002",
"southwest": RPATH "m_p006_p001",

    ]));
}

