//forest37.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest38",
                "southeast":TFOREST"forest36",
                ]));
}

