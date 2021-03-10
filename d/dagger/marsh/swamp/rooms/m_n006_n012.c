#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_n007_n013",
"north": RPATH "m_n006_n011",
"east": RPATH "m_n005_n012",

    ]));
}

