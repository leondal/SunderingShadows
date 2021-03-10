#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p003_n005",
"south": RPATH "m_p004_n005",
"southeast": RPATH "m_p005_n005",
"northeast": RPATH "m_p005_n003",

    ]));
}

