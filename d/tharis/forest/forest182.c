//forest182.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest183",
                //"enter":TFOREST"evil1",
                "northwest":TFOREST"forest181",
                "up":TFOREST"up30"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up30");

}


