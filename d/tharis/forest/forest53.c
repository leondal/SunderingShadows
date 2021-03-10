//forest53.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest31",
                "northwest":TFOREST"forest52",
                ]));
    find_object_or_load(TFOREST"forest48");
}

