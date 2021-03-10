#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p007_n004",
"south": RPATH "m_p006_n004",
"west": RPATH "m_p005_n003",
"east": RPATH "m_p007_n003",

    ]));
}

