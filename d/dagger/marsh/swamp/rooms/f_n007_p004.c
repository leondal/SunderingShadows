#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"east": RPATH "f_n006_p004",
"west": RPATH "f_n008_p004",
"southeast": RPATH "f_n006_p003",

    ]));
}

