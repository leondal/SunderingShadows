//	lane4.c
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
    set_short("On the lane towards the castle");
    set("day long",
@DAY
You are on a road leading to the Marleen castle to the north.  You
really don't know what to think of it, because it doesn't look well
preserved.  You feel though that there is adventure towards the north.
The wood is on both sides of the lane and the oak trees that stand
beside the road are very old and creepy.
DAY
    );
    set("night long",
@NIGHT
You are on a lane towards the castle that you see to the north. You feel that it is a nice place for newbies. The oaks who are lining the road block most of the moonlight here.

NIGHT
    );
set_listen("default","The woods reveal wood-like noises.");
    set_exits(([
"south" : CASTLE+"lane3",
"north" : CASTLE+"castle1"
    ] ));
set_items(([ "oaks" : "The oaks are lining the road and are very old.",
	     "wood" : "It is on both sides of the lane and it is too thick to enter.",
	     "castle" : "It is to the north." ]));
   
}
