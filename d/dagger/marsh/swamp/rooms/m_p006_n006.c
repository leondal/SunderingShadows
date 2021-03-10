#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p005_n006",
"northwest": RPATH "m_p005_n005",
"southeast": RPATH "m_p007_n007",

    ]));
}

