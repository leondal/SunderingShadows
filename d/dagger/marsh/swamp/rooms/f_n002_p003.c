#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n001_p003",
"southwest": RPATH "f_n003_p002",
"south": RPATH "f_n002_p002",
"northeast": RPATH "f_n001_p004",
"southeast": RPATH "f_n001_p002",

    ]));
}

