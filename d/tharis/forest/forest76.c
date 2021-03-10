//forest76.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest75",
                "northeast":TFOREST"forest77",
                ]));
    find_object_or_load(TFOREST"forest74");
}

