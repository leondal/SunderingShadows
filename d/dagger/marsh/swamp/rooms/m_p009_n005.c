#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p010_n005",
"northwest": RPATH "m_p008_n004",

    ]));
}

