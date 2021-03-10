#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_p008_p003",
"south": RPATH "m_p007_p002",

    ]));
}

