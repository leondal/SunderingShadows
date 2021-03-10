#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "west" : FRPATH "for27",
        "east" : FRPATH "for6",
        "south" : FRPATH "for4",
        "southwest" : FRPATH "for26",
    ]));
}
