#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n002_p004",
"southwest": RPATH "f_n002_p003",
"east": RPATH "f_p000_p004",

    ]));
}

