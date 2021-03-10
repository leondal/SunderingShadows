//hill12.c

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
to the west. There are tracks in the dirt and some small 
tents scattered around the hills. You see more people and 
animals here than other places.
JAVAMAKER
   );

   set_smell("default","You smell the plants surrounding you.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "animals":"Pack animals are hitched to carts.",
      "tents":"These look like temporary storage or sleeping places.",
      "tracks":"There are tracks of small pack animals and people.",
      "people":"They are gnomes who appear a bit apprehensive at strangers walking around.",
   ]));

   set_exits(([
      "south":HILL"hill13",
      "northwest":HILL"hill5",
      "east":HILL"hill18",
      "north":HILL"hill11",
      "northeast":HILL"hill17",
      "west":HILL"hill6",
      "southeast":HILL"hill19",
      "southwest":HILL"hill7",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







