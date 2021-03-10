//forest36.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest37",
                "south":TFOREST"forest35",
                ]));
}

