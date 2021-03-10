//forest178.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest179",
                "southwest":TFOREST"forest177"
                ]));
    find_object_or_load(TFOREST"forest177");
    find_object_or_load(TFOREST"forest180");

}

