#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_n005_n004",
"southwest": RPATH "m_n007_n004",

    ]));
}

