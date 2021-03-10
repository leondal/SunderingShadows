#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_n003_n011",
"southwest": RPATH "m_n004_n013",
"southeast": RPATH "m_n002_n013",
"northwest": RPATH "m_n004_n011",

    ]));
}

