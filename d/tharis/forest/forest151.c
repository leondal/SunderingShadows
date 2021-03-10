//forest151.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest140",
                "northwest":TFOREST"forest152",
                ]));
}

