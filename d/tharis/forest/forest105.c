//forest102.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest122",
                "southeast":TFOREST"forest104",
                "northwest":TFOREST"forest132",
                "up":TFOREST"up20",
                ]));
    set_invis_exits(({"up"}));
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
    find_object_or_load(TFOREST"up20");

}

