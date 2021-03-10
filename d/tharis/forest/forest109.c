//forest109.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest74",
                "north":TFOREST"forest110",
                ]));
    find_object_or_load(TFOREST"forest117");
}

