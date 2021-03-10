#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n004_p006",
"east": RPATH "f_n002_p007",
"south": RPATH "f_n003_p006",

    ]));
}

