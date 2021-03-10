//forest71.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest106",
                "south":TFOREST"forest70",
                "east":TFOREST"forest72",
                "up":TFOREST"up10"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up10");

}


