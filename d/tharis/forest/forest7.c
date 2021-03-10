//forest7.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest6",
                "southwest":TFOREST"forest8"
    ]));
}

