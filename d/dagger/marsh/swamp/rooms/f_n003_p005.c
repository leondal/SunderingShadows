#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n004_p005",
"south": RPATH "f_n003_p004",

    ]));
}

