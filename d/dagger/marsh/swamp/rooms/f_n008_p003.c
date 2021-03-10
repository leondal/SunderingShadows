#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_n008_p002",
"west": RPATH "f_n009_p003",

    ]));
}

