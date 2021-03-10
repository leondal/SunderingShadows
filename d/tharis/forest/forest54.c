//forest54.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest49",
                "northeast":TFOREST"forest59",
                ]));
    find_object_or_load(TFOREST"forest48");
}

