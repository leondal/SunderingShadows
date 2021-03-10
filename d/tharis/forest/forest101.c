//forest100.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest100",
                "northwest":TFOREST"forest102",
                ]));
    find_object_or_load("/d/tharis/forest/forest89");
}

