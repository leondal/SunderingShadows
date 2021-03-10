//forest51.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest52",
                "northwest":TFOREST"forest50",
                ]));
}

