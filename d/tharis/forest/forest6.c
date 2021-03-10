//forest6.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest5",
                "southwest":TFOREST"forest7"
                ]));
}

