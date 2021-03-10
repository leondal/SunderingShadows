//forest88.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest87",
                "north":TFOREST"forest89",
                ]));
    find_object_or_load(TFOREST"forest63");
}

