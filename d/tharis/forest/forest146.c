//forest146.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest145",
                "north":TFOREST"forest144"
                ]));

}

