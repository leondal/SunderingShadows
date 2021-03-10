#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_n002_p003",
"east": RPATH "f_n001_p002",

    ]));
}

