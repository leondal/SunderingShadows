//forest115.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest114",
                "west":TFOREST"forest117",
                ]));
    find_object_or_load(TFOREST"forest74");
}

