//forest89.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest100",
                "south":TFOREST"forest88",
                "west":TFOREST"forest92",
                "up":TFOREST"up15"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up14");

}


