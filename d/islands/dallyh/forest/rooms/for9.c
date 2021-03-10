#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "southwest" : FRPATH "for8",
        "northeast" : FRPATH "for10",
        "west" : FRPATH "for16",
    ]));
}
