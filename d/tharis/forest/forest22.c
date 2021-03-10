//forest22.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest5",
                "east":TFOREST"forest23"
                ]));
    if(find_object_or_load(TFOREST"forest27"));
}

