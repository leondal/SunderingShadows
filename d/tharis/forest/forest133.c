//forest133.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest131",
                "northeast":TFOREST"forest134",
                ]));
    find_object_or_load(TFOREST"forest134");
    find_object_or_load(TFOREST"forest131");

}

