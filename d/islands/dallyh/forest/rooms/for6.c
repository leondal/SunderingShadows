#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "west" : FRPATH "for5",
        "northeast" : FRPATH "for7",
    ]));
}

