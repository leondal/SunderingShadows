//forest63.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest70a",
                "west":TFOREST"forest62",
                "northeast":TFOREST"forest93",
                "north":TFOREST"forest86",
                "up":TFOREST"up9"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up9");
}


