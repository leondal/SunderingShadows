//forest107.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest106",
                "north":TFOREST"forest108",
                ]));
    find_object_or_load(TFOREST"forest71");
}

