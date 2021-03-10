#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n002_n005",
"southeast": RPATH "m_n001_n007",

    ]));
}

