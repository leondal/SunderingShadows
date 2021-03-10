//forest28.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest27",
                "east":TFOREST"forest29",
                ]));
}

