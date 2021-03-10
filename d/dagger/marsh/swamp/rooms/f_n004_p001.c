#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n003_p001",
"southwest": RPATH "f_n005_p000",
"west": RPATH "f_n005_p001",

    ]));
}

