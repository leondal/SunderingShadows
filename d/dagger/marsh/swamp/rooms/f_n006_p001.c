#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_n006_p002",
"southwest": RPATH "f_n007_p000",
"northwest": RPATH "f_n007_p002",
"west": RPATH "f_n007_p001",

    ]));
}

