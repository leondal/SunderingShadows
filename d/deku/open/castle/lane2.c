//	lane2.c
//	Pator@ShadowGate
//	Fri May 12 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_light(0);
    set_indoors(0);
    set_short("On a lane");
    set("day long",
@DAY
You are walking on a lane lined with heavy oaks.  The forest on
both sides can't be entered because it is too thick. To the southeast 
there is a path toward the village of Solace and to the north you
see the towers of a castle.
DAY
    );
    set("night long",
@NIGHT
This lane is lined with oaks and the forest after them is very
thick and you can't seem to enter it.  The oaks are blocking 
most of the moonlight.  You see a trail, probably towards the
village and you notice some towers towards the north.
NIGHT
    );
set_listen("default","The woods reveal wood-like noises.");
    set_exits(([
"southeast" : CASTLE+"lane1",
"north" : CASTLE+"lane3"
    ] ));
set_items(([ "oaks" : "The oaks are lining the road and are very old.",
	     "forest" : "It is on both sides of the lane and it is too thick to enter.",
	     "castle" : "It is to the north.",
	     "trail" : "This trail was once a gracefull lane, but is now no more than a horsetrack."]));
   
}
