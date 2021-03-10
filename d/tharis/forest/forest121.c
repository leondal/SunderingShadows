//forest121.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest122",
                "southwest":TFOREST"forest120",
                ]));
    find_object_or_load(TFOREST"forest105");
}

