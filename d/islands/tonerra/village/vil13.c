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
You are on the eastern side of the village. There are
tall wooden posts that surround the village making a sort
fence from the jungle. You can see some small huts scattered 
to the west, surrounding a much larger hut toward the center
of the village.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear the sounds of animals on the other side of the fence.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "southwest":I_VILLAGE+"vil14",
	      "northeast":I_VILLAGE+"vil12"
  ]));
}

	     
