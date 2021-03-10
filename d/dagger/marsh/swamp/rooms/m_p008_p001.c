#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p008_p002",
"northeast": RPATH "m_p009_p002",
"southwest": RPATH "m_p007_p000",

    ]));
}

