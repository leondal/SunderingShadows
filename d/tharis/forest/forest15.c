//forest15.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest14",
                "northwest":TFOREST"forest39",
                "northeast":TFOREST"forest64a",
             ]));
}

