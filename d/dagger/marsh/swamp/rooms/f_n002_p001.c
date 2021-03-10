#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "f_n001_p000",
"west": RPATH "f_n003_p001",

    ]));
}

