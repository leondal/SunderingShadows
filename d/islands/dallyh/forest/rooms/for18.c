#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "southwest" : FRPATH "for20",
        "south" : FRPATH "for17",
        "northeast" : FRPATH "for19",
    ]));
}
