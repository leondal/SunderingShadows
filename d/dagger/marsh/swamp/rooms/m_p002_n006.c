#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p001_n005",
"northeast": RPATH "m_p003_n005",
"southeast": RPATH "m_p003_n007",
"southwest": RPATH "m_p001_n007",

    ]));
}

