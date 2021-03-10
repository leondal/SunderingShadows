//forest167.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest164",
                "southwest":TFOREST"forest166"
                ]));
    find_object_or_load(TFOREST"forest164");
    find_object_or_load(TFOREST"forest166");
}

