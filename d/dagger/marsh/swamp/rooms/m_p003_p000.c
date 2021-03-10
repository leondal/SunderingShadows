#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p003_n001",
"west": RPATH "m_p002_p000",

    ]));
}

