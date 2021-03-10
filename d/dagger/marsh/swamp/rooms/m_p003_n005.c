#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p003_n006",
"southwest": RPATH "m_p002_n006",
"northeast": RPATH "m_p004_n004",
"east": RPATH "m_p004_n005",

    ]));
}

