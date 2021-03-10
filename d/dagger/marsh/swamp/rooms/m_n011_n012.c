#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n011_n011",
"south": RPATH "m_n011_n013",

    ]));
}

