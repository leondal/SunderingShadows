//forest172.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest173",
                "south":TFOREST"forest150"
                ]));
    find_object_or_load(TFOREST"forest140");
}

