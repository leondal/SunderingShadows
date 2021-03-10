#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
                   "northwest": RPATH "m_p008_n008",
                   "east": "/d/dagger/marsh/path7",
                   ]));
}
