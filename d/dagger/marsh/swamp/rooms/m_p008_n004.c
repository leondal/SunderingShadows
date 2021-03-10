#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p007_n004",
"southeast": RPATH "m_p009_n005",
"east": RPATH "m_p009_n004",

    ]));
}

