//forest42.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest43",
                "southeast":TFOREST"forest41",
                ]));
    find_object_or_load(TFOREST"forest38");
}

