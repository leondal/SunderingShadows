//forest58.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest59",
                "northwest":TFOREST"forest57",
                ]));
    find_object_or_load(TFOREST"forest55");
}

