//forest41.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest42",
                "northeast":TFOREST"forest40",
                ]));
    find_object_or_load(TFOREST"forest38");
}

