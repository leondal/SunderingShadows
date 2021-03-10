//forest45.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest48",
                "southwest":TFOREST"forest44",
                "northwest":TFOREST"forest47"
    ]));
}

