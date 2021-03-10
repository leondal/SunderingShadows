//forest134.c

#include <std.h>
#include "./forest.h"

inherit EFOREST;

void create(){
    ::create();
    set_exits(([
                "southwest":TFOREST"forest133",
                "southeast":TFOREST"forest132",
                "northeast":TFOREST"forest165",
                "up":TFOREST"up24",
                "enter":TFOREST"forest2d"

                ]));
    set_invis_exits(({"up"}));
    find_object_or_load(TFOREST"up24");

    set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));

}

int GoThroughDoor(){
    write("%^CYAN%^A shimmer of light flashes and leaves you in another part of the forest, Evil's power must be great!");
    return 1;
}

