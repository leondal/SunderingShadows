#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n008_n007",
"northwest": RPATH "m_n009_n007",
"southeast": RPATH "m_n007_n009",

    ]));
}

