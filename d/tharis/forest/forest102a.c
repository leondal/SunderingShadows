//forest102a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest99",
                "southwest":TFOREST"forest102",
                ]));
    find_object_or_load(TFOREST"forest99");
    find_object_or_load(TFOREST"forest102");
}

