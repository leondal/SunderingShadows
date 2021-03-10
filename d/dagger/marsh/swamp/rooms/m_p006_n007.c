#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p005_n006",
"east": RPATH "m_p007_n007",

    ]));
}

