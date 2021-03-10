#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p009_n002",
"northeast": RPATH "m_p009_p000",
"south": RPATH "m_p008_n002",
"northwest": RPATH "m_p007_p000",

    ]));
}

