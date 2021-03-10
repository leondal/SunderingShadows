#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "southeast" : FRPATH "for14",
        "west" : FRPATH "for10",
        "northeast" : FRPATH "for12",
    ]));
}
