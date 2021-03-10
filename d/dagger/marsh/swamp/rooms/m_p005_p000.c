#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p005_n001",
"north": RPATH "m_p005_p001",
"southwest": RPATH "m_p004_n001",
"east": RPATH "m_p006_p000",
"southeast": RPATH "m_p006_n001",

    ]));
}

