#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northwest" : FRPATH "forest7",
        "south" : FRPATH "forest5",
    ]));
}
