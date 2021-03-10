//hill22.c

#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/inherit/hilltents";

void create(){ 
   ::create();
   set_property("no teleport",1);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);   
   set_short("Rolling hills");
   set_long(
@JAVAMAKER
You are walking through some rolling hills. Small plants
cover the hills surrounding you. The hills flatten out some
to the west. There are tracks in the dirt and quite a few 
small tents scattered around the hills.
JAVAMAKER
   );

   set_smell("default","You smell the plants surrounding you.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tents":"These look like temporary storage or sleeping places.",
      "tracks":"There are tracks of small pack animals and people.",
      "people":"They are gnomes who appear a bit apprehensive at strangers walking around.",
   ]));

   set_exits(([
      "north":HILL"hill21",
      "northeast":HILL"hill27",
      "east":HILL"hill28",
      "southeast":HILL"hill29",
      "south":HILL"hill23",
      "southwest":HILL"hill17",
      "west":HILL"hill16",
      "northwest":HILL"hill15",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}
