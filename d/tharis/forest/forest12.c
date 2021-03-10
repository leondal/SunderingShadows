//forest12.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest11",
                "north":TFOREST"forest13"
                ]));
}

