#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n009_p003",
"east": RPATH "f_n007_p004",

    ]));
}

