#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "west" : FRPATH "forest9",
        "northeast" : FRPATH "forest11",
    ]));
}
