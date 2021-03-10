//forest135.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest99",
                "north":TFOREST"forest160",
                "northwest":TFOREST"forest136"
    ]));
    find_object_or_load(TFOREST"forest164");

}

