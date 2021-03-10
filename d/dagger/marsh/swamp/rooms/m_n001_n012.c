#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_n001_n013",
"southwest": RPATH "m_n002_n013",
"northeast": RPATH "m_p000_n011",
"north": RPATH "m_n001_n011",

    ]));
}

