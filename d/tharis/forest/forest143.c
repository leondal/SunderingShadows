//forest143.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest142",
                "north":TFOREST"forest147"
                ]));

}

