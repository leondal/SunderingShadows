//forest158.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest155",
                "northwest":TFOREST"forest159"
                ]));
    find_object_or_load(TFOREST"forest177");
}

