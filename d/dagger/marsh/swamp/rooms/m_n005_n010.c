#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n006_n011",
"southeast": RPATH "m_n004_n011",
"northwest": RPATH "m_n006_n009",

    ]));
}

