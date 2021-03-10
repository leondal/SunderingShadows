//forest159.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest158",
                "northwest":TFOREST"forest177"
                ]));
    find_object_or_load(TFOREST"forest177");
}

