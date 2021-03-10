#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "m_p005_n002",
"northwest": RPATH "m_p005_p000",
"southeast": RPATH "m_p007_n002",
"northeast": RPATH "m_p007_p000",

    ]));
}

