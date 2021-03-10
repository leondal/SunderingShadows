#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_n008_n002",
"north": RPATH "f_n008_p000",

    ]));
}

