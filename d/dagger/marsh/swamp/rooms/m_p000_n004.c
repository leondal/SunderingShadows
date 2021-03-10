#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p001_n005",
"west": RPATH "m_n001_n004",

    ]));
}

