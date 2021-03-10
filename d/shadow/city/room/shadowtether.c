//Circe 4/23/04
#include <std.h>
#include "../defs.h"

inherit "/d/common/inherit/hitching_post";

void create()  {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_long("%^RESET%^%^ORANGE%^Like the larger room to the west, "+ 
"this area is enclosed by sturdy "+ 
"wooden walls.  The floor is covered in %^RESET%^sawdust "+
"%^RESET%^%^ORANGE%^and %^RESET%^hay%^RESET%^%^ORANGE%^, and beneath "+ 
"it seems to be made of dirt. Several tethering posts have been "+ 
"set around the room, providing a place for riders to %^RESET%^<tether>%^ORANGE%^ their "+ 
"mounts while they are in the city.%^RESET%^\n");
	set_smell("default","%^CYAN%^The smell of hay and manure mix together.");
	set_listen("default","%^GREEN%^An occassional whinny reaches your ears, along with a snort or so.%^RESET%^");
  set_exits(([
             "west" : ROOMS"stable",
  ]));
  set_items( ([
      ({"post","posts","hitching post","hitching posts","tether","tethering post","tethering posts"}) : "There are several posts set up here to tether horses to. They are"+
	" basically long wooden bars that are supported on either end"+
	" that you loop the reins of a horse around to keep them there."+
	" There are four posts all together, circling a round, wooden trough.",
   ]) );
      set_pre_exit_functions(({"west"}),({"GoThroughDoor"}));

}
