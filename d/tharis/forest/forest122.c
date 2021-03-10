//forest122.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest121",
                "northeast":TFOREST"forest105",
                ]));
    find_object_or_load(TFOREST"forest120");
}

