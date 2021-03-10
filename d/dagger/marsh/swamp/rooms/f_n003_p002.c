#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n002_p003",
"west": RPATH "f_n004_p002",

    ]));
}

