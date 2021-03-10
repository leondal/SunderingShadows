//ferry05.c

#include <std.h>
#include "Pepitom.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);

   set_short(
@JAVAMAKER
Ferry Road
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You are on the beach of LostLore Lake
You can see an island off in the distance to the north.
There is a ferry landing to the east.

JAVAMAKER
   );

   set_smell("default","You smell the Fresh air drifting from the lake");
   set_listen("default","You can hear the waves on the beach.");
   set_items(([
   ]));

   set_exits(([
      "south":ROOMS+"ferry04.c",
      "east":ROOMS+"ferryland.c",
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







