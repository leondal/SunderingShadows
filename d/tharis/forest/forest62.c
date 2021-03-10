//forest61.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest63",
                "west":TFOREST"forest61",
                ]));
    find_object_or_load(TFOREST"forest59");
}

