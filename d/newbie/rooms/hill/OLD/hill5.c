//hill5.c

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
to the west. There are tracks in the dirt and some small 
tents and huts scattered around the nearby hills.  When you
%^BOLD%^<peer west> %^RESET%^you can see a gravel trail.
JAVAMAKER
   );

   set_smell("default","You smell the plants surrounding you.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tents":"These look like temporary storage or sleeping places.",
      "tracks":"There are tracks of small pack animals and people.",
      "huts":"These look like homes.",
   ]));

   set_exits(([
      "southeast":HILL"hill12",
      "northeast":HILL"hill10",
      "west":HILL"hill2",
      "south":HILL"hill6",
      "east":HILL"hill11",
      "north":HILL"hill4",
      "northwest":HILL"hill1",
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







