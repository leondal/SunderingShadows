#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "m_n009_n011",
"south": RPATH "m_n010_n013",
"southwest": RPATH "m_n011_n013",

    ]));
}

