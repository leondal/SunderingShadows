//forest99.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest135",
                "southwest":TFOREST"forest102a",
                "southeast":TFOREST"forest98",
                "up":TFOREST"up22"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up14");

}


