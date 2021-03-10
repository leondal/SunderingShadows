#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n002_p007",
"southeast": RPATH "f_p000_p007",

    ]));
}

