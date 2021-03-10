//forest77.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest125",
                "southwest":TFOREST"forest76",
                "southeast":TFOREST"forest78",
                "up":TFOREST"up12"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up12");

}


