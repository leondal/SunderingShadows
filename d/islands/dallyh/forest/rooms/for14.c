#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "northwest" : FRPATH "for11",
        "east" : FRPATH "for15",
    ]));
}
