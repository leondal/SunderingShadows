#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p006_p002",
"southeast": RPATH "m_p006_p000",
"northwest": RPATH "m_p004_p002",
"east": RPATH "m_p006_p001",
"south": RPATH "m_p005_p000",

    ]));
}

