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
You are pretty much in the middle of all the huts in 
the village. There is a hut south of you, and paths 
leading throughout the village in the other directions.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the sounds of animals on the other side of the fence.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "northwest":I_VILLAGE+"vil61",
	      "northeast":I_VILLAGE+"vil64",
	      "south":I_VILLAGE+"hut4"
  ]));
}

	     
