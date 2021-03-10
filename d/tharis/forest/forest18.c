//forest18.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest17",
                "southeast":TFOREST"forest46",
                "east":TFOREST"forest19",
                "up":TFOREST"up3"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up3");

}


