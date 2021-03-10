#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p009_n002",
"southwest": RPATH "m_p007_n004",
"north": RPATH "m_p008_n002",

    ]));
}

