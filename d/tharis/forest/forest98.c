//forest98.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest97",
                "northwest":TFOREST"forest99",
                ]));
}

