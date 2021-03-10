#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n002_p001",
"west": RPATH "f_n004_p001",

    ]));
}

