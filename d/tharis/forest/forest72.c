//forest72.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest71",
                "east":TFOREST"forest73",
                ]));
    find_object_or_load(TFOREST"forest74");

}

