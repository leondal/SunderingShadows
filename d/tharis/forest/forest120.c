//forest120.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest124",
                "southwest":TFOREST"forest82",
                "southeast":TFOREST"forest119",
                "northeast":TFOREST"forest121",
                "up":TFOREST"up19"
                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up19");

}


