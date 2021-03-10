#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "southwest" : FRPATH "for6",
        "north" : FRPATH "for8",
    ]));
}
