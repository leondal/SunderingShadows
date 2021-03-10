#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "m_p009_n006",
"southwest": RPATH "m_p008_n008",
"southeast": "/d/dagger/marsh/path8",
    ]));
}
