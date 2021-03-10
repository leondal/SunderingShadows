//road9.c

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
You are standing at the northern end of what used to be a town. From the
state of the buildings and rubble around you, it appears that the town
has not been inhabited for a long time. To the north is the gravel trail
that leads throughout the land.
NEWBIE
    );
    set_smell("default","You smell the fresh air of the open land.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_exits(([
       "north":ROAD"road44",
       "south":N_RUINS"road8",
   ]));
}





