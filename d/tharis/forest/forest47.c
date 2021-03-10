//forest47.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest45",
                "northwest":TFOREST"forest46"
                ]));
    find_object_or_load(TFOREST"forest18");
}

