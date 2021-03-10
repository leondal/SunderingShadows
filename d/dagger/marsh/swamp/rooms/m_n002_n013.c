#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n001_n012",
"northwest": RPATH "m_n003_n012",
"east": RPATH "m_n001_n013",

    ]));
}

