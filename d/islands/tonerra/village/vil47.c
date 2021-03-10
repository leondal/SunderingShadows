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
You are on a pathway leading into the village. There is a
pathway leading toward the center of the village to the 
south. You can see some small huts scattered all around 
you, surrounding a much larger hut toward the center of 
the village. There is a path leading to a small hut east
of you.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the sounds of animals on the other side of the fence.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "north":I_VILLAGE+"vil44",
	      "south":I_VILLAGE+"vil51",
	      "east":I_VILLAGE+"vil48"
  ]));
}

	     
