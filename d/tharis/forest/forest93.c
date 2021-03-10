//forest93.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest63",
                "northeast":TFOREST"forest94",
                ]));
    find_object_or_load(TFOREST"forest99");
}

