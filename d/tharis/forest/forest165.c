//forest165.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest166",
                "southwest":TFOREST"forest134"
                ]));
    find_object_or_load(TFOREST"forest166");
}

