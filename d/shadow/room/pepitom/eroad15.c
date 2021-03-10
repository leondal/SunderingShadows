//eroad15.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
East Main Street
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on the East Main street of Pepitom.
There are farms all around.
You see a building to the northeast.
There is an alley to the west.
JAVAMAKER
   );

   set_smell("default","You smell the odor of fresh manure.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "west":ROOMS+"ealley05.c",
      "north":ROOMS+"eroad16.c",
      "east":ROOMS+"eroad14.c",
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







