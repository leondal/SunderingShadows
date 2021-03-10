//forest56.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest57",
                "northwest":TFOREST"forest55",
                ]));
    find_object_or_load(TFOREST"forest59");
}

