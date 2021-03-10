//forest69a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest66a",
                "southeast":TFOREST"forest68a",
                ]));
    find_object_or_load(TFOREST"forest55");
}

