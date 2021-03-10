#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "east" : FRPATH "for11",
        "southwest" : FRPATH "for9",
    ]));
}
