//road52.c Road from Offestry west gate to ruins

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
    set_short("A wide gravel trail");
    set_long(
@NEWBIE
You are on a wide gravel trail just outside the gates of the city.  It 
runs to the west across mostly open land.  You can see a forest off in 
the distance to the southeast and the ruins of another town to the south
and west.
NEWBIE
    );
    set_smell("default","You smell the fresh air of the open land.");
    set_listen("default","You hear the sound of the wind rushing across the open land.");
    set_exits(([
       "west":ROAD"road51",
       "east":MAINTOWN"wroad1",
   ]));
}
