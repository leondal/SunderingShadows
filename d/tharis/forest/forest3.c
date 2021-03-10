//forest2.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest4",
                "south":TFOREST"forest2"
                ]));
}

