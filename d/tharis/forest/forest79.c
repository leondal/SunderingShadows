//forest79.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest66a",
                "northeast":TFOREST"forest80",
                ]));
    find_object_or_load(TFOREST"forest120");
}

