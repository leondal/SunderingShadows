#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p004_n008",
"south": RPATH "m_p004_n010",

    ]));
}

