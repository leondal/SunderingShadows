//forest66.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest67",
                "southwest":TFOREST"forest31",
                ]));
    find_object_or_load(TFOREST"forest63");
}

