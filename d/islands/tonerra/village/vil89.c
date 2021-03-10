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
You are on a pathway through the center of the village.
You can see some small huts scattered to the south of you, 
surrounding a much larger hut further south. An open space
is off to the southeast.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the normal sounds of a village.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "southeast":I_VILLAGE+"vil88",
	      "northwest":I_VILLAGE+"vil46",
  ]));
}

	     
