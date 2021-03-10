//forest46.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest47",
                "northwest":TFOREST"forest18"
                ]));
    find_object_or_load(TFOREST"forest48");
}

