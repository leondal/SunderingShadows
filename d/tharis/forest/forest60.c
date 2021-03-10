//forest60.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest61",
                "northwest":TFOREST"forest59",
                ]));
    find_object_or_load(TFOREST"forest63");
}

