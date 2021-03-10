//forest64a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest65a",
                "southwest":TFOREST"forest15",
                ]));
    find_object_or_load(TFOREST"forest66a");
}

