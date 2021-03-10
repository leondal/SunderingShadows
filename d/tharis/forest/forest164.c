//forest164.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest170",
                "southeast":TFOREST"forest163",
                "southwest":TFOREST"forest167",
                "up":TFOREST"up27"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up27");

}


