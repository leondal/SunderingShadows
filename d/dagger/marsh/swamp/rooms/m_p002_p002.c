#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p003_p003",
"northwest": RPATH "m_p001_p003",
"southwest": RPATH "m_p001_p001",
"west": RPATH "m_p001_p002",

    ]));
}

