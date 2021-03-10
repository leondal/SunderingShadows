//forest92.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest91",
                "east":TFOREST"forest89",
                ]));
    find_object_or_load(TFOREST"forest85");
}

