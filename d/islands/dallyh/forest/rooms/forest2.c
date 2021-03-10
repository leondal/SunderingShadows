#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northeast" : FRPATH "forest9",
        "northwest" : FRPATH "forest3",
        "south" : FRPATH "forest1",
    ]));
}
