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
You are on a pathway just before a small hut. There is a
pathway leading through the center of the village to the 
west. You can see some small huts scattered all around you, 
surrounding a much larger hut to the southwest.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear strange sounds from inside the hut.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "west":I_VILLAGE+"vil73",
	      "east":I_VILLAGE+"hut9",
  ]));
}

	     
