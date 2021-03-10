//forest2.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest2b",
                "east":TFOREST"forest2d"
                ]));
}

