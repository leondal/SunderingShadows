#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n003_n004",
"north": RPATH "m_n002_n002",
"southeast": RPATH "m_n001_n004",

    ]));
}

