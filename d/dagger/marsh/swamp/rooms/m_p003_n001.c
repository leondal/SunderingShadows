#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p002_n002",
"northwest": RPATH "m_p002_p000",
"north": RPATH "m_p003_p000",
"east": RPATH "m_p004_n001",

    ]));
}

