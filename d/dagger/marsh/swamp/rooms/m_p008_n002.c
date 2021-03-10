#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p008_n003",
"southwest": RPATH "m_p007_n003",
"north": RPATH "m_p008_n001",
"west": RPATH "m_p007_n002",

    ]));
}

