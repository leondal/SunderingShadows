//forest170.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest171",
                "southeast":TFOREST"forest164"
                ]));
    find_object_or_load(TFOREST"forest184");
    find_object_or_load(TFOREST"forest164");
}

