//forest64.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest61",
                "south":TFOREST"forest65",
                ]));
}

