#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_p000_p003",
"north": RPATH "f_p000_p005",
"west": RPATH "f_n001_p004",

    ]));
}

