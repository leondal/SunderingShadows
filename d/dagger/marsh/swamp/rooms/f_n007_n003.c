#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_n007_n002",
"northwest": RPATH "f_n008_n002",
"southeast":RPATH "m_n008_n005",
    ]));
}
