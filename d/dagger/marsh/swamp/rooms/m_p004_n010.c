#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p003_n009",
"north": RPATH "m_p004_n009",
"southeast": RPATH "m_p005_n011",

    ]));
}

