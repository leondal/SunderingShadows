//forest34.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest35",
                "east":TFOREST"forest33",
                ]));
}

