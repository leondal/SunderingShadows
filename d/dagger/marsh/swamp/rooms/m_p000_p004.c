#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "m_p000_p003",
"southeast": RPATH "m_p001_p003",
"northwest": RPATH "m_n001_p005",

    ]));
}

