#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p002_n006",
"southeast": RPATH "m_p004_n008",
"southwest": RPATH "m_p002_n008",

    ]));
}

