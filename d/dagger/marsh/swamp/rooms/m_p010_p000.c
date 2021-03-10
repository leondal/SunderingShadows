#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p009_p000",
"southeast": RPATH "m_p011_n001",
"southwest": RPATH "m_p009_n001",
"north": RPATH "m_p010_p001",

    ]));
}

