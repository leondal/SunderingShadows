//forest68.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest69",
                "south":TFOREST"forest67",
                ]));
}

