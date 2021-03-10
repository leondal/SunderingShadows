//forest162.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest164",
                "southeast":TFOREST"forest162"
                ]));
    find_object_or_load(TFOREST"forest135");
}

