#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "south" : FRPATH "for7",
        "northeast" : FRPATH "for9",
    ]));
}
