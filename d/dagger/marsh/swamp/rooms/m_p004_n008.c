#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p004_n007",
"northwest": RPATH "m_p003_n007",
"south": RPATH "m_p004_n009",

    ]));
}

