#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n003_p007",
"northeast": RPATH "f_n001_p008",
"southeast": RPATH "f_n001_p006",
"south": RPATH "f_n002_p006",

    ]));
}

