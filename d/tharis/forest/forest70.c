//forest70.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest71",
                "south":TFOREST"forest38",
                ]));
    find_object_or_load(TFOREST"forest38");
    find_object_or_load(TFOREST"forest71");

}

