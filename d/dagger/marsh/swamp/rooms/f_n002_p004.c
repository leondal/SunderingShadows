#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n003_p003",
"northeast": RPATH "f_n001_p005",
"east": RPATH "f_n001_p004",

    ]));
}

