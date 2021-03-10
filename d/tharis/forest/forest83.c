//forest83.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest55",
                "northeast":TFOREST"forest84",
                ]));
    find_object_or_load(TFOREST"forest85");
}

