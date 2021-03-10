//forest11.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest10",
                "northeast":TFOREST"forest12"
                ]));
}

