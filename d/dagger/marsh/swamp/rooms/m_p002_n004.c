#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p002_n003",
"southwest": RPATH "m_p001_n005",

    ]));
}

