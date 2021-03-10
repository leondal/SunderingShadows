#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p001_n002",
"north": RPATH "m_p002_n002",
"south": RPATH "m_p002_n004",

    ]));
}

