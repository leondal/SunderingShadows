#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northwest" : FRPATH "forest4",
        "southeast" : FRPATH "forest2",
    ]));
}
