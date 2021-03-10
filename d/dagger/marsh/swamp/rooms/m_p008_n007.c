#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p009_n006",
"west": RPATH "m_p007_n007",

    ]));
}

