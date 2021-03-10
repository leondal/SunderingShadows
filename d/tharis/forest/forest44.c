//forest44.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest45",
                "southwest":TFOREST"forest24",
                ]));
    find_object_or_load(TFOREST"forest48");
}

