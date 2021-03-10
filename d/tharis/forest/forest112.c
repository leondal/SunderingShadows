//forest112.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest111",
                "north":TFOREST"forest113",
                ]));
}

