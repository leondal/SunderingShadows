#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p005_p001",
"southeast": RPATH "m_p007_p000",
"northeast": RPATH "m_p007_p002",

    ]));
}

