//forest129.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest131",
                "southwest":TFOREST"forest129",
                ]));
    find_object_or_load(TFOREST"forest127");
}

