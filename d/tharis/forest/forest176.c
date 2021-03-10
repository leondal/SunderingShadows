//forest176.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest177",
                "south":TFOREST"forest149"
                ]));
    find_object_or_load(TFOREST"forest177");
}

