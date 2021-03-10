#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n005_n006",
"northwest": RPATH "m_n005_n004",
"northeast": RPATH "m_n003_n004",

    ]));
}

