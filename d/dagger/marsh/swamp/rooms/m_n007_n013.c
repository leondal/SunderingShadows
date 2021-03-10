#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n006_n012",
"west": RPATH "m_n008_n013",

    ]));
}

