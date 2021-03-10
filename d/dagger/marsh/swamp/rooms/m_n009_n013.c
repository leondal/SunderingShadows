#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n010_n013",
"east": RPATH "m_n008_n013",

    ]));
}

