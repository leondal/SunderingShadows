#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p007_n009",
"north": RPATH "m_p007_n007",

    ]));
}

