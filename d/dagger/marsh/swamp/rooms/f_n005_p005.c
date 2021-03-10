#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n006_p004",
"north": RPATH "f_n005_p006",
"east": RPATH "f_n004_p005",
"southeast": RPATH "f_n004_p004",

    ]));
}

