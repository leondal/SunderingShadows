//forest16.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest13",
                "east":TFOREST"forest17"
                ]));
    find_object_or_load(TFOREST"forest18");
}

