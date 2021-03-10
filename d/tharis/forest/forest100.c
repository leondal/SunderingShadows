//forest100.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest89",
                "north":TFOREST"forest101",
                ]));
    find_object_or_load("/d/tharis/forest/forest102");
}

