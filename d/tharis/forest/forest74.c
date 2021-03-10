//forest74.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest109",
                "southwest":TFOREST"forest73",
                "northeast":TFOREST"forest75",
                "up":TFOREST"up11"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up11");

}


