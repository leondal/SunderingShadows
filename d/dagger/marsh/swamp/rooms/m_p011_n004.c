#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p010_n005",
"west": RPATH "m_p010_n004",
"north": RPATH "m_p011_n003",
"northwest": RPATH "m_p010_n003",

    ]));
}

