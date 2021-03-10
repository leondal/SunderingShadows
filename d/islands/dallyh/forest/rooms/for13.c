#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "south" : FRPATH "for12",
        "north" : FRPATH "forest1",
    ]));
}
