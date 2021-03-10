#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p002_n008",
"southeast": RPATH "m_p004_n010",
"west": RPATH "m_p002_n009",

    ]));
}

