//forest127.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest126",
                "southeast":TFOREST"forest128",
                "north":TFOREST"forest139",
                "up":TFOREST"up18"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up18");

}


