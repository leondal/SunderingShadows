#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p002_p002",
"northwest": RPATH "m_p000_p003",
"south": RPATH "m_p001_p001",

    ]));
}

