#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n005_n012",
"east": RPATH "m_n004_n013",

    ]));
}

