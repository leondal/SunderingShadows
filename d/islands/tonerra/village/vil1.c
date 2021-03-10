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
You are at an entrance to a village in the middle of
the jungle. The wooden posts that surround the village
stop on either side of the dirt path. You can see some
small huts scattered around the area, surrounding a much
larger hut toward the center of the village.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the sounds of the jungle outside the gates.");
  set_smell("default","You smell the recently fallen rain and the moisture around you.");
  set_exits(([
	      "west":PATH+"path12",
	      "north":I_VILLAGE+"vil2",
	      "south":I_VILLAGE+"vil41",
	      "east":I_VILLAGE+"vil42"
  ]));
}

	     
