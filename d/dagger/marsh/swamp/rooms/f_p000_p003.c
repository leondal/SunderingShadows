#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_p000_p004",
"west": RPATH "f_n001_p003",
"northeast": RPATH "f_p001_p004",

    ]));
}

