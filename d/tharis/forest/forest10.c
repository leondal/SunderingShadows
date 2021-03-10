//forest10.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest9",
                "north":TFOREST"forest11"
                ]));
}

