//forest49.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest50",
                "northwest":TFOREST"forest48",
                "northeast":TFOREST"forest54",
    ]));
    find_object_or_load(TFOREST"forest59");
}

