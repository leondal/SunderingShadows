//forest117.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest145",
                "south":TFOREST"forest116",
                "east":TFOREST"forest115",
                "up":TFOREST"up17"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up17");

}


