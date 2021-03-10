#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "south" : FRPATH "for21",
        "northeast" : FRPATH "for18",
    ]));
}
