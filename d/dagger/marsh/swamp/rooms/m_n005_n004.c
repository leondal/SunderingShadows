#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n005_n005",
"southeast": RPATH "m_n004_n005",
"northwest": RPATH "m_n006_n003",

    ]));
}

