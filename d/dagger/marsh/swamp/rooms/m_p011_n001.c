#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p011_n002",
"west": RPATH "m_p010_n001",
"northwest": RPATH "m_p010_p000",

    ]));
}

