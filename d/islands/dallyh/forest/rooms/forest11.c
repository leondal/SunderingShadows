#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "southwest" : FRPATH "forest10",
        "north" : FRPATH "forest12",
    ]));
}
