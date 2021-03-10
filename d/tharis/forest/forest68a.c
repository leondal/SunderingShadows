//forest68a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest69a",
                "southeast":TFOREST"forest67a",
                ]));
    find_object_or_load(TFOREST"forest66");
}

