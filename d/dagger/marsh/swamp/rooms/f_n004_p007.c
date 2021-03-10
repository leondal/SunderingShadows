#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_n004_p006",
"west": RPATH "f_n005_p007",

    ]));
}

