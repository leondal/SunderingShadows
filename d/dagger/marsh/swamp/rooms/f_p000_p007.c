#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
"southwest": RPATH "f_n001_p006",
"northwest": RPATH "f_n001_p008",
"south": RPATH "f_p000_p006",
"west": RPATH "f_n001_p007",
"southeast":RPATH"m_n001_p005",
    ]));
}
