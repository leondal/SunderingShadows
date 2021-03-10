//forest125.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest77",
                "north":TFOREST"forest126",
                ]));
    find_object_or_load(TFOREST"forest127");

}

