#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "f_n002_p007",
"northeast": RPATH "f_p000_p007",
"east": RPATH "f_p000_p006",

    ]));
}

