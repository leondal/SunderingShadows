//forest2.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest2",
                "east":TFOREST"forest2b"
                ]));
}

