//mroad01.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
Main Street
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on the main street of Pepitom.
There are shops to either side of the road.
JAVAMAKER
   );

   set_smell("default","You smell the smoke from a fire pit.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "south":ROOMS+"road10.c",
      "north":ROOMS+"mroad02.c",
      "east":ROOMS+"stable.c",
      "west":ROOMS+"inn.c",
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







