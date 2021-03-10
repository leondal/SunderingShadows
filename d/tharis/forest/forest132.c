//forest132.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest134",
                "southeast":TFOREST"forest105",
                ]));
    find_object_or_load(TFOREST"forest134");
    find_object_or_load(TFOREST"forest105");

}

