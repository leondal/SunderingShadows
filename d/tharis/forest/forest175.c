//forest175.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest180",
                              "southwest":TFOREST"forest174"
                ]));
    find_object_or_load(TFOREST"forest180");
}

