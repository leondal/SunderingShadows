//forest61.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest62",
                "west":TFOREST"forest60",
                "south":TFOREST"forest64"
    ]));
}

