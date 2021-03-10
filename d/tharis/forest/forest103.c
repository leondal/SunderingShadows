//forest103.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest102",
                "northwest":TFOREST"forest104",
                ]));
    find_object_or_load(TFOREST"forest105");
}

