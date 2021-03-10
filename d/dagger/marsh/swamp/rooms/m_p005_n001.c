#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p005_p000",
"south": RPATH "m_p005_n002",

    ]));
}

