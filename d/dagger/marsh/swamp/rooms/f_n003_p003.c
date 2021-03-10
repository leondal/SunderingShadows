#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"northeast": RPATH "f_n002_p004",
"southwest": RPATH "f_n004_p002",

    ]));
}

