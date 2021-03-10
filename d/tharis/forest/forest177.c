//forest177.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "northeast":TFOREST"forest178",
                "southeast":TFOREST"forest159",
                "southwest":TFOREST"forest176",
                "up":TFOREST"up28"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up28");

}


