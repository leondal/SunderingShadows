#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n008_n002",
"northwest": RPATH "f_n008_p000",

    ]));
}

