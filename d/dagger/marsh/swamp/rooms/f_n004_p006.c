#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n005_p006",
"north": RPATH "f_n004_p007",
"northeast": RPATH "f_n003_p007",

    ]));
}

