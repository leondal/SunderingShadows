//hill14.c - with random tent

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);   
   set_short("Rolling hills");
   set_long(
@JAVAMAKER
You are walking through some rolling hills. Small plants
cover the hills surrounding you. The hills flatten out some
to the west. There are tracks in the dirt and quite a few 
small tents scattered around the hills. To the north, the hills
appear uninhabited.
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
      "south":HILL"hill15",
      "east":HILL"hill20",
      "southeast":HILL"hill21",
      "west":HILL"hill8",
      "southwest":HILL"hill9",
   ]));
   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}

void reset(){
   ::reset();
}
