#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n005_p004",
"northwest": RPATH "f_n005_p005",

    ]));
}

