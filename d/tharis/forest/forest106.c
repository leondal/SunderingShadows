//forest106.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest71",
                "north":TFOREST"forest107",
                ]));
    find_object_or_load(TFOREST"forest108");
}

