//forest119.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest120",
                "southeast":TFOREST"forest118",
                ]));
    find_object_or_load(TFOREST"forest85");
}

