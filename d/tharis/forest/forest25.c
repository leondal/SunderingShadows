//forest25.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest24",
                "south":TFOREST"forest26",
                ]));
}

