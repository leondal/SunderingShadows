//forest17.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest16",
                "east":TFOREST"forest18"
                ]));
}

