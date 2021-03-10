//forest173.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest174",
                "south":TFOREST"forest172"
                ]));
    find_object_or_load(TFOREST"forest180");
}

