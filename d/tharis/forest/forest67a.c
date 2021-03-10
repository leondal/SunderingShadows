//forest67a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest68a",
                "southeast":TFOREST"forest21",
                ]));
    find_object_or_load(TFOREST"forest66");
}

