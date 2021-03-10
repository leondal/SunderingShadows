#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n007_n004",
"southwest": RPATH "m_n008_n006",

    ]));
}

