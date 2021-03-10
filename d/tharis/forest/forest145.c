//forest145.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest117",
                "north":TFOREST"forest146",
    ]));
}

