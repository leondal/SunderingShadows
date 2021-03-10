//forest168.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest169",
                "south":TFOREST"forest166"
                ]));
    find_object_or_load(TFOREST"forest184");
    find_object_or_load(TFOREST"forest166");
}

