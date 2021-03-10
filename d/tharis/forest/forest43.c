//forest43.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest38",
                "southeast":TFOREST"forest42",
                ]));
    find_object_or_load(TFOREST"forest38");
}

