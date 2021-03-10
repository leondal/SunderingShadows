//ealley01.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
Eastern Alley
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are in the alley between farm fields.
There are farms all around.


JAVAMAKER
   );

   set_smell("default","You smell the odor of fresh manure.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "south":ROOMS+"eroad06.c",
      "north":ROOMS+"ealley02.c",
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







