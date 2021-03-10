#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p001_n002",
"north": RPATH "m_p000_p000",

    ]));
}

