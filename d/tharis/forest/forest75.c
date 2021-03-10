//forest75.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest74",
                "east":TFOREST"forest76",
                ]));
    find_object_or_load(TFOREST"forest77");
}

