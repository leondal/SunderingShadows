#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n005_p003",
"southwest": RPATH "f_n007_p002",
"northwest": RPATH "f_n007_p004",

    ]));
}

