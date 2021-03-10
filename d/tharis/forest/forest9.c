//forest9.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest5",
                "north":TFOREST"forest10"
                ]));
    find_object_or_load(TFOREST"forest13");
}

