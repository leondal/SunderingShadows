//forest69.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest70a",
                "south":TFOREST"forest68",
                ]));
}

