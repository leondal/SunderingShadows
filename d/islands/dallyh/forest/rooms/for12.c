#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "southwest" : FRPATH "for11",
        "north" : FRPATH "for13",
    ]));
}
