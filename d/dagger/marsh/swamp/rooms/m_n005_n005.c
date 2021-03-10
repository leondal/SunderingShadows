#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n005_n004",
"northwest": RPATH "m_n006_n004",
"south": RPATH "m_n005_n006",
"southwest": RPATH "m_n006_n006",

    ]));
}

