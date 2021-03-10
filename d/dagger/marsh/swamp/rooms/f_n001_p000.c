#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_n001_p001",
"northwest": RPATH "f_n002_p001",
"southeast": RPATH "m_n002_n002",
    ]));
}
