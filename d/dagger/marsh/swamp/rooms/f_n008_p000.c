#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "f_n009_p001",
"southeast": RPATH "f_n007_n001",
"east": RPATH "f_n007_p000",
"south": RPATH "f_n008_n001",

    ]));
}

