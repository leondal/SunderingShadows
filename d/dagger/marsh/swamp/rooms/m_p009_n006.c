#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p010_n005",
"south": RPATH "m_p009_n007",
"southwest": RPATH "m_p008_n007",

    ]));
}

