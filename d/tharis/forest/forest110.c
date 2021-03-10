//forest110.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest109",
                "north":TFOREST"forest111",
                ]));
}

