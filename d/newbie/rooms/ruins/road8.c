//road7.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain(RUINS);
    set_travel(DIRT_ROAD);
    set_short("The ruins of a town.");
    set_long(
@NEWBIE
You are standing at a forkroad in the abandoned ruins of a town. From the
state of the buildings and rubble around you, it appears that the town
has not been inhabited for a long time. To the north is the gravel trail
that leads throughout the land. The road through the town leads to the
east and the west.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_exits(([
        "north":N_RUINS"road9",
        "east":N_RUINS"eroad7",
        "south":N_RUINS"road7",
        "west":N_RUINS"wroad7",
    ]));
}





