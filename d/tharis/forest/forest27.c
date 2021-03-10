//forest27.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest26",
                "east":TFOREST"forest28",
                "up":TFOREST"up4"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up4");
}
