#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p009_p000",
"west": RPATH "m_p007_p000",

    ]));
}

