//wroad1.c

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
You are walking along a street through the abandoned ruins of a town.
From the state of the buildings and rubble around you, it appears that
the town has not been inhabited for a long time. Stone and wood litter
the sides of the road where buildings used to be.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_items(([
        "buildings":"Most of the buildings appear to be little more than partial walls left standing.",
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "northwest":N_RUINS"wroad2",
        "east":N_RUINS"road2",
    ]));
}





