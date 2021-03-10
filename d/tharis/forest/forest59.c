//forest59.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest54",
                "southeast":TFOREST"forest60",
                "northwest":TFOREST"forest58",
                "up":TFOREST"up8"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up8");
}


