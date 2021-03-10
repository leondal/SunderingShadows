#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n005_p006",
"west": RPATH "f_n007_p006",

    ]));
}

