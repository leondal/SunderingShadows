//forest126.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest125",
                "north":TFOREST"forest127",
                ]));
    find_object_or_load(TFOREST"forest77");

}

