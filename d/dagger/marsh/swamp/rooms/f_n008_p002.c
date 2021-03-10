#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "f_n009_p002",
"northeast": RPATH "f_n007_p003",
"southeast": RPATH "f_n007_p001",
"north": RPATH "f_n008_p003",

    ]));
}

