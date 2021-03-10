#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "m_p003_p003",
"southeast": RPATH "m_p005_p001",

    ]));
}

