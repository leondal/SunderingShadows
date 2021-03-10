#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_n003_n008",
"west": RPATH "m_n005_n007",

    ]));
}

