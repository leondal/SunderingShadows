//forest2.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest2a",
                "east":TFOREST"forest2c"
                ]));
}

