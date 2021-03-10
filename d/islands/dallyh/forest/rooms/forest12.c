#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "south" : FRPATH "forest11",
        "east" : FRPATH "forest13",
    ]));
}
