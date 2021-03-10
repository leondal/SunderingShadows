//forest161.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest162",
                "southeast":TFOREST"forest160"
                ]));
    find_object_or_load(TFOREST"forest164");
}

