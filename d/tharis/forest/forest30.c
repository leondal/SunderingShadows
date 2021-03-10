//forest30.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest29",
                "east":TFOREST"forest31",
                ]));
}

