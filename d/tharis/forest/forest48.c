//forest48.c

#include <std.h>
#include "./forest.h"

inherit GFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest45",
                "southeast":TFOREST"forest49",
                "up":TFOREST"up6"
                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up6");
}
