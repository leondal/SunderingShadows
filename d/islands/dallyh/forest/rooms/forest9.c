#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "east" : FRPATH "forest10",
        "southwest" : FRPATH "forest2",
    ]));
}
