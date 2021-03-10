#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "f_n008_p006",
"east": RPATH "f_n006_p005",
"west": RPATH "f_n008_p005",

    ]));
}

