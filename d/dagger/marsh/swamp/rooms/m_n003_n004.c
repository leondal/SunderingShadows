#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n004_n005",
"southeast": RPATH "m_n002_n005",
"northeast": RPATH "m_n002_n003",

    ]));
}

