//forest180.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest181",
                "south":TFOREST"forest175",
              "out":"/d/tharis/conforest/rooms/f77",
                "southwest":TFOREST"forest179",
                "up":TFOREST"up29"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up29");

}

