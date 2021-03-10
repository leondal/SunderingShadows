//forest82.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest81",
                "northeast":TFOREST"forest120",
                ]));
    find_object_or_load(TFOREST"forest66a");

}

