//forest84.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest83",
                "northeast":TFOREST"forest85",
                ]));
    find_object_or_load(TFOREST"forest55");
}

