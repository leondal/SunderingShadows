//forest166.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest165",
                "northeast":TFOREST"forest167",
                "north":TFOREST"forest168",
                "up":TFOREST"up26"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up26");

}


