#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "m_n007_n013",
"west": RPATH "m_n009_n013",
"northwest": RPATH "m_n009_n012",

    ]));
}

