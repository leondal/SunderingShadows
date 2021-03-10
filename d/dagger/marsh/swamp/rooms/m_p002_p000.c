#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p003_n001",
"east": RPATH "m_p003_p000",
"northwest": RPATH "m_p001_p001",

    ]));
}

