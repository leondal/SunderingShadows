#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "north" : FRPATH "for22",
        "southwest" : FRPATH "for24",
    ]));
}
