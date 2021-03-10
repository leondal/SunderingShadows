#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    
    set_exits(([
        "north" : FRPATH "for20",
        "southeast" : FRPATH "road1",
        "southwest" : FRPATH "for22",
    ]));
}
