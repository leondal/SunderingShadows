//forest33.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest34",
                "southeast":TFOREST"forest32",
                ]));
}

