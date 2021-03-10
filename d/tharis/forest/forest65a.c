//forest65a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest66a",
                "southwest":TFOREST"forest64a",
                ]));
    find_object_or_load(TFOREST"forest13");
}

