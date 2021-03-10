//forest26.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest25",
                "south":TFOREST"forest27",
                ]));
}

