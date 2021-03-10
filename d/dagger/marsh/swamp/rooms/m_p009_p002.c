#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p008_p002",
"southeast": RPATH "m_p010_p001",
"northwest": RPATH "m_p008_p003",
"southwest": RPATH "m_p008_p001",

    ]));
}

