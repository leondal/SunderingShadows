//forest80.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest79",
                "northeast":TFOREST"forest81",
                ]));
}

