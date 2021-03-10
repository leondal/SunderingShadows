#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "m_p004_p002",
"southwest": RPATH "m_p002_p002",
"northeast": "/d/dagger/marsh/witchlair/rooms/archway",
    ]));
}
