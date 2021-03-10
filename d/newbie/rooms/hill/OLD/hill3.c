//hill3.c

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
You are on the edge of some gently rolling hills. There is
open land to the north and more hills to the east and south.
You can see closely spaced tracks in the dirt and some 
small tents and huts scattered around the hills.
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tents":"These look like temporary storage or sleeping places.",
      "tracks":"There are tracks of small pack animals and people.",
      "huts":"These look like homes.",
   ]));

   set_exits(([
      "east":HILL"hill9",
      "south":HILL"hill4",      
      "southeast":HILL"hill10",
      "northeast":HILL"hill8",
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







