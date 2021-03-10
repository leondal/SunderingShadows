#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_p000_p003",
"north": RPATH "f_p001_p005",
"northwest": RPATH "f_p000_p005",

    ]));
}

