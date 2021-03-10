#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "north" : FRPATH "forest2",
        "south" : FRPATH "for13",
    ]));
}
