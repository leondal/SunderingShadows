//forest131.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest130",
                "southeast":TFOREST"forest124",
                "northeast":TFOREST"forest133",
                "up":TFOREST"up23"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up23");

}


