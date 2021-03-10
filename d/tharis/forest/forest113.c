//forest113.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest112",
                "northwest":TFOREST"forest114",
                ]));
}

