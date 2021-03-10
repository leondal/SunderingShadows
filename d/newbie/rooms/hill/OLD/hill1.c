//hill1.c

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
You are on the edge of some gently rolling hills. There is
a pathway to the west and more hills to the east and south.
You can see closely spaced tracks in the dirt.
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the hills.");
   set_items(([
      "tracks":"There are tracks of small pack animals and people.",
   ]));

   set_exits(([
      "east":HILL"hill4",
      "southeast":HILL"hill5",
      "west":ROAD"road10",
      "south":HILL"hill2",
      "southwest":ROAD"road11",
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







