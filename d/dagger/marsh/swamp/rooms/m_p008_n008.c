#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p007_n009",
"northeast": RPATH "m_p009_n007",
"northwest": RPATH "m_p007_n007",
"southeast": RPATH "m_p009_n009",

    ]));
}

