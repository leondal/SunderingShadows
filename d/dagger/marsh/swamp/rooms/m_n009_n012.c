#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n009_n011",
"southeast": RPATH "m_n008_n013",

    ]));
}

