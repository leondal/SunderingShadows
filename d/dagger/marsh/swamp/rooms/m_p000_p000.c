#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p000_n001",
"southwest": RPATH "m_n001_n001",
"northeast": RPATH "m_p001_p001",

    ]));
}

