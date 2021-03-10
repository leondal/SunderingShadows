//forest2.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest3",
                "south":TFOREST"forest1",
                "east":TFOREST"forest2a"
    ]));
}

