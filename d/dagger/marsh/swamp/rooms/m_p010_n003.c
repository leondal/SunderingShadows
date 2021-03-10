#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p009_n002",
"northeast": RPATH "m_p011_n002",
"south": RPATH "m_p010_n004",
"southeast": RPATH "m_p011_n004",

    ]));
}

