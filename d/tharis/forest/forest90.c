//forest90.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest91",
                "west":TFOREST"forest85",
                ]));
    find_object_or_load(TFOREST"forest89");
}

