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
You are on a pathway leading into the village. Two paths 
lead toward the center of the village from this point. You 
can see some small huts scattered all around you to the south,
surrounding a much larger hut directly south of you. 
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the sounds of animals on the other side of the fence.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "north":I_VILLAGE+"vil6",
	      "southwest":I_VILLAGE+"vil45",
	      "southeast":I_VILLAGE+"vil89"
  ]));
}

	     
