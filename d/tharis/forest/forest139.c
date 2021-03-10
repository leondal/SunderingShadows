//forest139.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest127",
                "north":TFOREST"forest140"
                ]));
    find_object_or_load(TFOREST"forest140");
    find_object_or_load(TFOREST"forest127");

}

