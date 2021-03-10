#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p005_p001",
"west": RPATH "m_p005_p000",

    ]));
}

