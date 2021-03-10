#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northwest" : FRPATH "for4",
        "southwest" : FRPATH "for2",
    ]));
}

