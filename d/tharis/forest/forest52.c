//forest52.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest53",
                "west":TFOREST"forest51",
                ]));
}

