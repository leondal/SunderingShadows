//forest67.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest68",
                "south":TFOREST"forest66",
                ]));
    find_object_or_load(TFOREST"forest63");
}

