//mroad02.c

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
The road splits here.
JAVAMAKER
   );

   set_smell("default","You smell the smoke from a fire pit.");
   set_listen("default","You can hear the occasional sound of people moving about the town.");
   set_items(([
   ]));

   set_exits(([
      "northwest":ROOMS+"wroad01.c",
      "northeast":ROOMS+"eroad01.c",
      "south":ROOMS+"mroad01.c",
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







