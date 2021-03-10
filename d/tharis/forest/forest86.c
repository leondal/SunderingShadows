//forest86.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest63",
                "north":TFOREST"forest87",
                ]));
    find_object_or_load(TFOREST"forest89");
}

