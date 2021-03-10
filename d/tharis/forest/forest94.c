//forest94.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest93",
                "northeast":TFOREST"forest95",
                ]));
}

