#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p006_p001",
"southwest": RPATH "m_p006_n001",
"east": RPATH "m_p008_p000",
"southeast": RPATH "m_p008_n001",
"northeast": RPATH "m_p008_p001",

    ]));
}

