//forest184.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "west":TFOREST"forest183",
                "south":TFOREST"forest169",
                "southeast":TFOREST"forest171",
                "up":TFOREST"up31"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up31");

}


