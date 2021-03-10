//forest39.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest40",
                "southeast":TFOREST"forest15",
                ]));
    find_object_or_load(TFOREST"forest38");
}

