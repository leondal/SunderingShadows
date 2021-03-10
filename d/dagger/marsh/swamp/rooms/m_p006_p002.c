#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p007_p002",
"southwest": RPATH "m_p005_p001",

    ]));
}

