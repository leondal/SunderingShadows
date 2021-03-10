#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p000_p004",
"southeast": RPATH "m_p001_p002",

    ]));
}

