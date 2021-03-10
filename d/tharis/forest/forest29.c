//forest29.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest28",
                "east":TFOREST"forest30",
                ]));
}

