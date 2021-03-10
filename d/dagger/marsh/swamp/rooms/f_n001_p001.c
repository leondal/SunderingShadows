#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_n001_p000",
"north": RPATH "f_n001_p002",

    ]));
}

