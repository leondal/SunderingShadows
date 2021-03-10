//forest162.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest163",
                "southeast":TFOREST"forest161"
                ]));
    find_object_or_load(TFOREST"forest164");
}

