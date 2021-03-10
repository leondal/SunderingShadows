//forest14.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest13",
                "northwest":TFOREST"forest15"
                ]));
}

