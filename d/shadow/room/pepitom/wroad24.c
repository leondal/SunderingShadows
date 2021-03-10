//wroad24.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
West Main Street
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on the West Main street of Pepitom.
There are farms all around.
There ia a path to the north, heading toward the lake.
JAVAMAKER
   );

   set_smell("default","You smell the odor of fresh manure.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "east":ROOMS+"wroad25.c",
      "west":ROOMS+"wroad23.c",
      "north":ROOMS+"ferry01.c",
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







