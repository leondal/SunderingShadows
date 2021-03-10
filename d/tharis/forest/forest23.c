//forest23.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest22",
                "southeast":TFOREST"forest24",
                ]));
}

