#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_terrain(VILLAGE);
  set_travel(DIRT_ROAD);
  set_short("A jungle village");
  set_long(
@DESC
You are on a pathway leading into the village. There is an
entrance to the village off to the southeast and a pathway 
leading toward the center of the village to the north. You
can see some small huts scattered all around you, surrounding
a much larger hut toward the center of the village. A small
hut is down a path to the east.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the normal sounds of a village.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "northwest":I_VILLAGE+"vil65",
	      "east":I_VILLAGE+"vil76",
	      "south":I_VILLAGE+"vil77"
  ]));
}

	     
