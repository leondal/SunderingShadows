#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "west" : FRPATH "forest12",
        "northeast" : FRPATH "forest14",
    ]));
}
