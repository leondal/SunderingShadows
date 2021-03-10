//forest128.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "east":TFOREST"forest129",
                "northwest":TFOREST"forest127",
                ]));
    find_object_or_load(TFOREST"forest131");

}

