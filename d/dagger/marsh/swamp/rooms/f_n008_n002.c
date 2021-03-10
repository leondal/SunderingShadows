#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "f_n007_n003",
"north": RPATH "f_n008_n001",
"northeast": RPATH "f_n007_n001",
"west": RPATH "f_n009_n002",
"northwest": RPATH "f_n009_n001",

    ]));
}

