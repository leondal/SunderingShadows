#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "north" : FRPATH "forest6",
        "south" : FRPATH "forest4",
    ]));
}
