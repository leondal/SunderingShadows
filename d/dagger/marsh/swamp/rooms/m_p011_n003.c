#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p011_n002",
"south": RPATH "m_p011_n004",

    ]));
}

