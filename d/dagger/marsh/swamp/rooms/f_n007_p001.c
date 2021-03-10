#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n006_p001",
"northwest": RPATH "f_n008_p002",
"north": RPATH "f_n007_p002",
"south": RPATH "f_n007_p000",

    ]));
}

