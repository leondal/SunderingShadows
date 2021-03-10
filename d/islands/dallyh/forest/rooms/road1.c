#include "/d/islands/dallyh/fways.h"

inherit DVIL;

void create()
{
    ::create();
    set_exits(([
        "northwest":FRPATH "for21",
        "south":FRPATH "road2",
    ]));
}
