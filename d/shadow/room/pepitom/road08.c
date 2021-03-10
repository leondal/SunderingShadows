//road08.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
Pepitom Road
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on the road to Pepitom.
The road wanders through the dense forest.
The trail is rundown.	
JAVAMAKER
   );

   set_smell("default","You Smell the pine from the trees.");
   set_listen("default","You can hear the birds singing and the wind whispering through the trees.");
   set_items(([
   ]));

   set_exits(([
      "southwest":ROOMS+"road07.c",
      "northeast":ROOMS+"road09.c",
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







