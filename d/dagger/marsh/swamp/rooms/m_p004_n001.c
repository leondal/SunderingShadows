#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p005_n002",
"west": RPATH "m_p003_n001",
"northeast": RPATH "m_p005_p000",

    ]));
}

