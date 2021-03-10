#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p005_n006",
"southeast": RPATH "m_p006_n006",
"northeast": RPATH "m_p006_n004",
"northwest": RPATH "m_p004_n004",

    ]));
}

