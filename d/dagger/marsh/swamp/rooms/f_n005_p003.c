#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n006_p002",
"east": RPATH "f_n004_p003",
"west": RPATH "f_n006_p003",

    ]));
}

