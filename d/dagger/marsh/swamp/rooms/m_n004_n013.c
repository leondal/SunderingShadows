#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_n005_n013",
"northeast": RPATH "m_n003_n012",

    ]));
}

