#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();

    set_exits(([
        "north" : FRPATH "for18",
        "southeast" : FRPATH "for16",
    ]));
}
