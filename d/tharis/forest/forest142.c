//forest142.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest141",
                "north":TFOREST"forest143"
                ]));

}

