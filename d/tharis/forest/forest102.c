//forest102.c

#include <std.h>
#include "./forest.h"

inherit NFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest102a",
                "southeast":TFOREST"forest101",
                "northwest":TFOREST"forest103",
                "up":TFOREST"up21"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load("/d/tharis/forest/up21");

}


