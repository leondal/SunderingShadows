#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_p000_p003",
"west": RPATH "f_n002_p003",

    ]));
}

