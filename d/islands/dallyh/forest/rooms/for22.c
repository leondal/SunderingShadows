#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northeast" : FRPATH "for21",
        "northwest" : FRPATH "for28",
        "south" : FRPATH "for23",

    ]));
}
