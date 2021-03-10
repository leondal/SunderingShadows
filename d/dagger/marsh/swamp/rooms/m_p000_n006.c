#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p001_n007",
"northeast": RPATH "m_p001_n005",
"south": RPATH "m_p000_n007",

    ]));
}

