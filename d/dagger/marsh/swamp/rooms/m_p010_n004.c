#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p010_n003",
"east": RPATH "m_p011_n004",

    ]));
}

