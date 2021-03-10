//forest150.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest140",
                "north":TFOREST"forest172"
                ]));

}

