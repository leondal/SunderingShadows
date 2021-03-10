//forest13.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest12",
                "northwest":TFOREST"forest14",
                "east":TFOREST"forest16",
                "up":TFOREST"up2"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up2");

}


