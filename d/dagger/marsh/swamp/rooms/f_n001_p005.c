#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n002_p004",
"west": RPATH "f_n002_p005",
"northwest": RPATH "f_n002_p006",

    ]));
}

