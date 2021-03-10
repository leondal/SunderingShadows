#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p003_n006",
"south": RPATH "m_p004_n008",
"northeast": RPATH "m_p005_n006",

    ]));
}

