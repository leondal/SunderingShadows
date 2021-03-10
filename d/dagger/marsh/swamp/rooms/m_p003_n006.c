#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p003_n005",
"southeast": RPATH "m_p004_n007",

    ]));
}

