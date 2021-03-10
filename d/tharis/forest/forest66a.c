//forest66a.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest65a",
                "southeast":TFOREST"forest69a",
                "northwest":TFOREST"forest78",
                "northeast":TFOREST"forest79",
                "up":TFOREST"up13"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up3");

}

