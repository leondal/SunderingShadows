//	castle1.c
//	Pator@ShadowGate
//	Tue Apr 11 05:25:17 1995

#include <castle.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
	set_author("pator");
    set_light(1);
    set_short("In front of the castle gates");
    set("day long",
@DAY
You are standing in front of the gates to Marleen's castle.  The
trees are standing close together blocking much of the direct sun-
light.  The gates are to the north and the moat is under the bridge
you are standing on.
DAY
    );
    set("night long",
@NIGHT
You are standing in front of the gates to Marleen's castle.  There
is some dim light coming from some torches within. You see the water
in the moat, reflecting some of the light.
NIGHT
    );
  set_items(([ "gates" : "The gates are made of wood and are very thick.  They will stand through many attacks",
	     "trees" : "Ever seen trees ??? These look the same !",
         "moat" : " Water. It makes it impossible to walk towards the walls. Swimming could help in that sense!",
	      "torches" : "Wood,tar,fire. No more complex than that !" ]));
set_listen("default","You hear nothing much except some birds singing.");
    set_exits(([
"south" : CASTLE+"lane4",
"north" : CASTLE+"castle2",
"down"  : CASTLE+"moat1"
    ] ));
   
}
