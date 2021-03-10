#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "northeast" : FRPATH "for23",
        "southeast" : FRPATH "for25",
    ]));
}
