//forest5.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest9",
                "south":TFOREST"forest4",
                "northwest":TFOREST"forest32",
                "southwest":TFOREST"forest6",
                "east":TFOREST"forest22",
                "up":TFOREST"up1",
                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up1");

}

