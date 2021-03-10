//barhome.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
The home of the twins who run the bar.
JAVAMAKER
   );

   set_long(
@JAVAMAKER
This is the home of the twins who run the bar. 
You see a bed in the corner of the room.
There is a fireplace in the center of the room.
The room is clean, and well kept.

JAVAMAKER
   );

   set_smell("default","You smell the sweet odor of Jasmine incense.");
   set_listen("default","You hear the crackling of the fire, in the fireplace.");
   set_items(([
      "fireplace":"A simple fireplace, with a small fire burning.",
      "bed":"A simple bed of straw, big enough for only one person..",
   ]));

   set_exits(([
      "west":ROOMS+"ealley06.c",
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







