//forest124.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest120",
                "northwest":TFOREST"forest131",
                ]));
    find_object_or_load(TFOREST"forest120");
    find_object_or_load(TFOREST"forest131");

}

