//forest40.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest41",
                "northeast":TFOREST"forest39",
                ]));
    find_object_or_load(TFOREST"forest38");
}

