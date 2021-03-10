#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_p002_p002",
"southeast": RPATH "m_p002_p000",
"north": RPATH "m_p001_p002",
"southwest": RPATH "m_p000_p000",

    ]));
}

