#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northeast" : FRPATH "for3",
        "south" : FRPATH "for1",
    ]));
}
