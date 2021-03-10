//wroad20.c

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
To the west is a shop.
JAVAMAKER
   );

   set_smell("default","You smell the odor of fresh manure.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "west":ROOMS+"gs_store.c",
      "east":ROOMS+"wroad21.c",
      "south":ROOMS+"wroad19.c",
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








