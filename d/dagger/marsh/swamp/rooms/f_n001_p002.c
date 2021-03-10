#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northwest": RPATH "f_n002_p003",
"west": RPATH "f_n002_p002",
"south": RPATH "f_n001_p001",

    ]));
}

