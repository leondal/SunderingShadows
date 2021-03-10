#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "f_n006_p001",
"south": RPATH "f_n007_p001",
"northeast": RPATH "f_n006_p003",

    ]));
}

