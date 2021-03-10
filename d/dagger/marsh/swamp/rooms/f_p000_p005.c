#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southeast": RPATH "f_p001_p004",
"south": RPATH "f_p000_p004",
"north": RPATH "f_p000_p006",

    ]));
}

