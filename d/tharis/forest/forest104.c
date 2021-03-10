//forest104.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest103",
                "northwest":TFOREST"forest105",
                ]));
    find_object_or_load(TFOREST"forest102");
}

