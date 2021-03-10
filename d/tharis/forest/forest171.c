//forest171.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest184",
                "southeast":TFOREST"forest170"
                ]));
    find_object_or_load(TFOREST"forest184");
    find_object_or_load(TFOREST"forest164");
}

