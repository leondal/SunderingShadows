#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p009_p000",
"south": RPATH "m_p010_p000",
"northwest": RPATH "m_p009_p002",

    ]));
}

