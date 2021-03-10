//forest85.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "northwest":TFOREST"forest118",
                "southwest":TFOREST"forest84",
                "east":TFOREST"forest90",
                "up":TFOREST"up14"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up14");

}


