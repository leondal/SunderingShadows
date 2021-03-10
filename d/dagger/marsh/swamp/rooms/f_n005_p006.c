#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n004_p006",
"northwest": RPATH "f_n006_p007",
"south": RPATH "f_n005_p005",
"west": RPATH "f_n006_p006",

    ]));
}

