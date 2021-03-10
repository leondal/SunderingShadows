//forest78.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest77",
                "southeast":TFOREST"forest66a",
                ]));
    find_object_or_load(TFOREST"forest77");
    find_object_or_load(TFOREST"forest66a");
}

