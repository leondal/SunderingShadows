//forest111.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest110",
                "northeast":TFOREST"forest112",
                ]));
}

