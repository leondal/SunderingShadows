#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n004_p003",
"north": RPATH "f_n003_p005",

    ]));
}

