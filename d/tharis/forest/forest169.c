//forest169.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest184",
                "south":TFOREST"forest168"
                ]));
    find_object_or_load(TFOREST"forest184");
    find_object_or_load(TFOREST"forest166");
}

