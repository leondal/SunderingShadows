#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"north": RPATH "f_n002_p007",
"southeast": RPATH "f_n001_p005",

    ]));
}

