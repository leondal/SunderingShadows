#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p001_n005",
"northwest": RPATH "m_n001_n004",

    ]));
}

