#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n005_p001",
"west": RPATH "f_n007_p000",

    ]));
}

