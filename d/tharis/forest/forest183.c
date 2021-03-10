//forest183.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest184",
                "southwest":TFOREST"forest182"
                ]));
    find_object_or_load(TFOREST"forest182");
    find_object_or_load(TFOREST"forest184");

}

