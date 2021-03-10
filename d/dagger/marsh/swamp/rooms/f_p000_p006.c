#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n001_p006",
"north": RPATH "f_p000_p007",
"south": RPATH "f_p000_p005",

    ]));
}

