#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p008_n003",
"southeast": RPATH "m_p010_n003",
"north": RPATH "m_p009_n001",
"northwest": RPATH "m_p008_n001",

    ]));
}

