#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p002_p002",
"northwest": RPATH "m_p000_p004",

    ]));
}

