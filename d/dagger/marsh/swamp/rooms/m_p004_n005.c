#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p003_n005",
"southeast": RPATH "m_p005_n006",
"north": RPATH "m_p004_n004",

    ]));
}

