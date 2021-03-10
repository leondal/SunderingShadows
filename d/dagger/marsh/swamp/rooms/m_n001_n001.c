#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p000_n002",
"southwest": RPATH "m_n002_n002",
"northeast": RPATH "m_p000_p000",

    ]));
}

