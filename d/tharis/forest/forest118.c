//forest118.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest119",
                "southeast":TFOREST"forest85",
                ]));
    find_object_or_load(TFOREST"forest120");
}

