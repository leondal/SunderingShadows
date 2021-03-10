#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"south": RPATH "f_n010_p001",
"north": RPATH "f_n010_p003",

    ]));
}

